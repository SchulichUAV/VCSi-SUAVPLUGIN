#include <iostream>
#include <fstream> // For file operations
#include <nlohmann/json.hpp> // For JSON parsing
#include "parameter.h"
#include "parameter.cxx"

using namespace std;
using json = nlohmann::json;

Parameter makeParameterFromJson(const string& id, const json& j, const string& type);

int main() {
    ifstream file("sw/apm.pdef.json");
    if (!file.is_open()) {
        cerr << "Error: could not open apm.pdef.json" <<   endl;
        return 1;  // or handle differently
    }
    json data;
    try {
        file >> data; // Use the stream operator to parse
    } catch (const json::parse_error& e) {
        cerr << "Error parsing JSON: " << e.what() <<   endl;
        return 1;
    }

    vector<Parameter> parameters;
    if (data.contains("")) {
        for (auto& [id, paramJson] : data[""].items()) {
            Parameter p = makeParameterFromJson(id, paramJson);
            parameters.push_back(p);
        }
    }
    return 0;
}

Parameter makeParameterFromJson(const string& id, const json& j, const string& type) {
    // auto defines a variable containing a callable object
    // The [&] means to capture all variables from the surrounding scope by reference
    auto get_opt_string = [&](const string& key) -> optional<string> {
        if (j.contains(key) && j[key].is_string())
            return j[key].get<string>();
        return nullopt;
    };

    auto get_opt_bool = [&](const string& key) -> optional<bool> {
        if (j.contains(key) && j[key].is_boolean())
            return j[key].get<bool>();
        return nullopt;
    };

    auto get_opt_float = [&](const string& key) -> optional<float> {
        if (j.contains(key) && j[key].is_number())
            return j[key].get<float>();
        return nullopt;
    };

    // Range handling
    optional<Range> range;
    if (j.contains("Range") && j["Range"].is_object()) {
        range = Range{
            j["Range"].value("Min", 0.0f),
            j["Range"].value("Max", 0.0f)
        };
    }

    // Optional maps (Values / Bitmask)
    optional<unordered_map<int, string>> values;
    if (j.contains("Values") && j["Values"].is_object()) {
         unordered_map<int,string> map; //creates an instance of a map
         //basically says for each key and value pair in values do:
        for (auto& [k, v] : j["Values"].items()) // maps k and v as key and value pairs to each instance in values
            map[stoi(k)] = v.get<string>(); //converts the string (k, key) to an int
        values = map; // values now becomes a map
    }

    optional<unordered_map<int, string>> bitmask;
    if (j.contains("Bitmask") && j["Bitmask"].is_object()) {
          unordered_map<int,string> map;
        for (auto& [k, v] : j["Bitmask"].items())
            map[stoi(k)] = v.get<string>();
        bitmask = map;
    }

    // Create and return a Parameter object
    return Parameter(
        id,
        j.value("Value", 0.0f),
        type,
        j.value("Description", ""), //Tries to read the string at key "Description".If it doesn’t exist or isn’t the right type, just uses an empty string
        j.value("DisplayName", ""),
        get_opt_string("User"),
        get_opt_string("Units"),
        get_opt_bool("RebootRequired"),
        get_opt_float("Increment"),
        get_opt_bool("ReadOnly"),
        j.contains("Calibration") ?   make_optional(j["Calibration"].get<int>()) :   nullopt,
        values,
        bitmask,
        range
    );
}

