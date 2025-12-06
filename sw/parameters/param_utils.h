#pragma once

#include <string>
#include <vector>
#include <optional>
#include <unordered_map>

#include <QJsonObject>
#include <QString>

#include "parameter.h"

class ParameterManager {
    private:
        std::string file_path;
        std::vector<Parameter> parameters;

        // Changed from const nlohmann::json& to const QJsonObject&
        Parameter make_parameter_from_json(const std::string& id, const QJsonObject& j);

    public:
        explicit ParameterManager(const std::string& path = "sw/parameters/apm.pdef.json");
        bool load();
        void print_parameters() const;
        std::vector<Parameter> &get_parameters();

};