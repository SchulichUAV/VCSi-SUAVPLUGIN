#include <iostream>
#include <string>
#include <optional>
#include <unordered_map>

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>

#include "parameter.h"
#include "param_utils.h"

using namespace std;



ParameterManager::ParameterManager(const string& path)
    : file_path(path) {}

bool ParameterManager::load() {
    QFile file(QString::fromStdString(file_path));

    if (!file.open(QIODevice::ReadOnly)) {
        cerr << "Error: could not open " << file_path << endl;
        return false;
    }

    const QByteArray fileData = file.readAll();
    file.close();

    QJsonParseError parseError;
    const QJsonDocument doc = QJsonDocument::fromJson(fileData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        cerr << "Error parsing JSON: "
             << parseError.errorString().toStdString() << endl;
        return false;
    }

    if (!doc.isObject()) {
        cerr << "Error: JSON is not an object." << endl;
        return false;
    }

    const QJsonObject data = doc.object();
    parameters.clear();

    constexpr int kMaxParams = 100;
    int added = 0;

    for (auto it = data.constBegin(); it != data.constEnd(); ++it) {
        const QString category = it.key();
        if (category == "json") continue;

        if (!it.value().isObject()) continue;
        const QJsonObject paramList = it.value().toObject();

        for (auto paramIt = paramList.constBegin(); paramIt != paramList.constEnd(); ++paramIt) {
            if (added >= kMaxParams) break;

            if (!paramIt.value().isObject()) continue;

            const string key = paramIt.key().toStdString();
            parameters.push_back(make_parameter_from_json(key, paramIt.value().toObject()));
            ++added;
        }

        if (added >= kMaxParams) break;
    }

    return true;
}

std::vector<Parameter> &ParameterManager::get_parameters() {
    return this->parameters;
}

void ParameterManager::print_parameters() const {
    for (const auto& p : parameters) {

        cout << p.getId() + ": " + p.getDisplayName() << endl;
        cout << "\tDescription: " + p.getDescription() << endl;

        if (p.getUser().has_value())
            cout << "\tUser: " << p.getUser().value() << endl;

        if (p.getUnits().has_value())
            cout << "\tUnits: " << p.getUnits().value() << endl;

        if (p.isRebootRequired().has_value())
            cout << "\tReboot required: " << (p.isRebootRequired().value() ? "true" : "false") << endl;

        if (p.getIncrement().has_value())
            cout << "\tIncrement: " << p.getIncrement().value() << endl;

        if (p.isReadOnly().has_value())
            cout << "\tRead-only: " << (p.isReadOnly().value() ? "true" : "false") << endl;

        if (p.getCalibration().has_value())
            cout << "\tCalibration: " << p.getCalibration().value() << endl;

        if (p.getValues().has_value()) {
            cout << "\tValues:" << endl;
            for (const auto& [key, val] : p.getValues().value()) {
                cout << "\t\t" << key << " = " << val << endl;
            }
        }

        if (p.getBitmask().has_value()) {
            cout << "\tBitmask:" << endl;
            for (const auto& [bit, name] : p.getBitmask().value()) {
                cout << "\t\t" << bit << " = " << name << endl;
            }
        }

        if (p.getRange().has_value()) {
            const Range& r = p.getRange().value();
            cout << "\tRange: [" << r.low << ", " << r.high << "]" << endl;
        }

        cout << endl;
    }
}

Parameter ParameterManager::make_parameter_from_json(const string& id, const QJsonObject& j) {
    auto get_opt_string = [&](const QString& key) -> optional<string> {
        if (j.contains(key)) {
            QJsonValue val = j.value(key);
            if (val.isString())
                return val.toString().toStdString();
        }
        return nullopt;
    };

    auto get_opt_bool = [&](const QString& key) -> optional<bool> {
        if (!j.contains(key)) return nullopt;
        
        QJsonValue val = j.value(key);
        if (val.isBool()) return val.toBool();
        
        if (val.isString()) {
            QString s = val.toString().toLower();
            if (s == "true" || s == "1") return true;
            if (s == "false" || s == "0") return false;
        }
        return nullopt;
    };

    auto get_opt_float = [&](const QString& key) -> optional<float> {
        if (!j.contains(key)) return nullopt;
        
        QJsonValue val = j.value(key);
        if (val.isDouble()) return static_cast<float>(val.toDouble());
        
        if (val.isString()) {
            bool ok;
            float f = val.toString().toFloat(&ok);
            if (ok) return f;
        }
        return nullopt;
    };

    auto get_opt_int = [&](const QString& key) -> optional<int> {
        if (!j.contains(key)) return nullopt;

        QJsonValue val = j.value(key);
        if (val.isDouble()) return static_cast<int>(val.toInt());
        
        if (val.isString()) {
            bool ok;
            int i = val.toString().toInt(&ok);
            if (ok) return i;
        }
        return nullopt;
    };

    float lowValue = 0.0f;
    float highValue = 0.0f;
    
    if (j.contains("Range")) {
        QJsonObject rangeObj = j.value("Range").toObject();
        
        auto get_range_val = [&](const QString& k) -> float {
            if (rangeObj.contains(k)) {
                QJsonValue v = rangeObj.value(k);
                if (v.isDouble()) return static_cast<float>(v.toDouble());
                if (v.isString()) return v.toString().toFloat();
            }
            return 0.0f;
        };

        lowValue = get_range_val("low");
        highValue = get_range_val("high");
    }

    optional<Range> range;
    range = Range{lowValue, highValue};
    
    if (lowValue == 0 && highValue == 0) {
        range = nullopt;
    }

    optional<unordered_map<string, string>> values;
    if (j.contains("Values") && j.value("Values").isObject()) {
        unordered_map<string, string> map;
        QJsonObject valuesObj = j.value("Values").toObject();
        
        for (auto it = valuesObj.constBegin(); it != valuesObj.constEnd(); ++it) {
            map[it.key().toStdString()] = it.value().toString().toStdString();
        }
        values = map;
    }

    optional<unordered_map<int, string>> bitmask;
    if (j.contains("Bitmask") && j.value("Bitmask").isObject()) {
        unordered_map<int, string> map;
        QJsonObject bitmaskObj = j.value("Bitmask").toObject();

        for (auto it = bitmaskObj.constBegin(); it != bitmaskObj.constEnd(); ++it) {
            try {
                int keyInt = std::stoi(it.key().toStdString());
                map[keyInt] = it.value().toString().toStdString();
            } catch (...) {
                // Handle parsing error if key isn't an integer string
                qDebug("Parsing error");
            }
        }
        bitmask = map;
    }

    ParameterType type_enum = ParameterType::UNKNOWN;
    
    string desc = "";
    if (j.contains("Description")) desc = j.value("Description").toString().toStdString();

    string dispName = "";
    if (j.contains("DisplayName")) dispName = j.value("DisplayName").toString().toStdString();

    return Parameter(
        id,
        0,
        type_enum,
        desc,
        dispName,
        get_opt_string("User"),
        get_opt_string("Units"),
        get_opt_bool("RebootRequired"),
        get_opt_float("Increment"),
        get_opt_bool("ReadOnly"),
        get_opt_int("Calibration"),
        values,
        bitmask,
        range
    );
}