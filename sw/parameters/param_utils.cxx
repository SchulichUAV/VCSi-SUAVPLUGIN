#include <iostream>
#include <fstream> // For file operations
#include <nlohmann/json.hpp> // For JSON parsing
#include <string>
#include <optional>
#include <unordered_map>
#include "parameter.h"
#include "param_utils.h"

using namespace std;
using json = nlohmann::json;

ParameterManager::ParameterManager(const string& path)
    : file_path(path) {}

bool ParameterManager::load() {
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Error: could not open apm.pdef.json" << endl;
        return false;
    }
    json data;
    try {
        file >> data;
    } catch (const json::parse_error& e) {
        cerr << "Error parsing JSON: " << e.what() << endl;
        return false;
    }

    parameters.clear();

    for (auto& [category, param] : data.items()) {
        if (category == "json") continue;

        for (auto& [key, value] : param.items()) {
            parameters.push_back(make_parameter_from_json(key, value));
        }
    }

    return true;

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

// It may be convenient to store the “param_type” field from the PARAM_VALUE 
//message sent by the flight controller for this parameter.
Parameter ParameterManager::make_parameter_from_json(const string& id, const json& j) {
    // auto defines a variable containing a callable object
    // The [&] means to capture all variables from the surrounding scope by reference
    //i.e. "[]"" can see variables made outside of the function, "&" uses the original variables from outside function
    const string& type_str = "UNKNOWN";

    //creates a mini function with auto
    //optional<string> is a C type that can contain a string or be empty
    auto get_opt_string = [&](const string& key) -> optional<string> {
        //If the JSON object has this key, and its value is a string
        if (j.contains(key) && j[key].is_string())
            return j[key].get<string>();
        return nullopt;
    };

    auto get_opt_bool = [&](const string& key) -> optional<bool> {
        if (!j.contains(key)) return nullopt;
        if (j[key].is_boolean()) return j[key].get<bool>();
        if (j[key].is_string()) {
            string val = j[key].get<string>();
            if (val == "true" || val == "1") return true;
            if (val == "false" || val == "0") return false;
        }
        return nullopt;
    };

    auto get_opt_float = [&](const string& key) -> optional<float> {
        if (!j.contains(key)) return nullopt;
        if (j[key].is_number()) return j[key].get<float>();
        if (j[key].is_string()) {
            try { return std::stof(j[key].get<string>()); }
            catch (...) { return nullopt; }
        }
        return nullopt;
    };

    auto get_opt_int = [&](const string& key) -> optional<int> {
        if (!j.contains(key)) return nullopt;
        if (j[key].is_number_integer()) return j[key].get<int>();
        if (j[key].is_string()) {
            try { return std::stoi(j[key].get<string>()); }
            catch (...) { return nullopt; }
        }
        return nullopt;
    };

    float lowValue = 0.0f;
    float highValue = 0.0f;
    if (j.contains("Range") && j["Range"].contains("low")) {
        if(j["Range"]["low"].is_string())
            lowValue = std::stof(j["Range"]["low"].get<std::string>());
        else if (j["Range"]["low"].is_number())
            lowValue = j["Range"]["low"].get<float>();
    }
    if (j.contains("Range") && j["Range"].contains("high")) {
        if(j["Range"]["high"].is_string())
            highValue = std::stof(j["Range"]["high"].get<std::string>());
        else if (j["Range"]["high"].is_number())
            highValue = j["Range"]["high"].get<float>();
    }
    optional<Range> range;
    range = Range{lowValue, highValue};
    
    if (lowValue == 0 && highValue == 0) {
        range = nullopt;
    }

    // Optional maps (Values / Bitmask)
    optional<unordered_map<string, string>> values;
    if (j.contains("Values") && j["Values"].is_object()) {
         unordered_map<string,string> map;
        for (auto& [k, v] : j["Values"].items())
            map[k] = v.get<string>();
        values = map;
    }

    optional<unordered_map<int, string>> bitmask;
    if (j.contains("Bitmask") && j["Bitmask"].is_object()) {
          unordered_map<int,string> map;
        for (auto& [k, v] : j["Bitmask"].items())
            map[stoi(k)] = v.get<string>();
        bitmask = map;
    }
    ParameterType type_enum = ParameterType::UNKNOWN;
    
    // Create and return a Parameter object
    return Parameter(
        id,
        0,
        type_enum,
        j.value("Description", ""), //Tries to read the string at key "Description".If it doesn’t exist or isn’t the right type, just uses an empty string
        j.value("DisplayName", ""),
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

