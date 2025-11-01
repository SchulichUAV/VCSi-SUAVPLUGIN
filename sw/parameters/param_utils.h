#pragma once

#include <iostream>
#include <fstream> // For file operations
#include <nlohmann/json.hpp> // For JSON parsing
#include <string>
#include <optional>
#include <unordered_map>
#include "parameter.h"

class ParameterManager {
    private:
        std::string file_path;
        std::vector<Parameter> parameters;

        Parameter make_parameter_from_json(const std::string& id, const nlohmann::json& j);

    public:
        explicit ParameterManager(const std::string& path = "sw/parameters/apm.pdef.json");
        bool load();
        void print_parameters() const;

};
