#include <iostream>
#include <fstream> // For file operations
#include <nlohmann/json.hpp> // For JSON parsing
#include <string>
#include <optional>
#include <unordered_map>
#include "parameter.h"
#include "parameter.cxx"

using namespace std;
using json = nlohmann::json;

Parameter makeParameterFromJson(const string& id, const json& j);

int main() {
    ifstream file("sw/apm.pdef.json");
    if (!file.is_open()) {
        cerr << "Error: could not open apm.pdef.json" <<   endl;
        return 1;  // or handle differently
    }
    json data;
    try {
        file >> data; // Use the stream operator to parse
        cout << "File opened successfully!" << endl;
    } catch (const json::parse_error& e) {
        cerr << "Error parsing JSON: " << e.what() <<   endl;
        return 1;
    }

    std::unordered_map<std::string, Parameter> parameters;
    json root;
    if (data.contains("") && data[""].is_object()) {
        // Case 1: file has { "parameters": { ... } }
        root = data[""];
        cout << "Detected '' root." << endl;
    } else {
        // Case 2: file directly contains groups like ADSB_, AFS_, etc.
        root = data;
        cout << "Detected grouped root." << endl;
    }
    cout << "Top-level keys: ";
    for (auto& [key, val] : data.items())
        cout << "[" << key << "] ";
    cout << endl;
    for (auto& [id, paramJson] : root.items()) {
        parameters.insert_or_assign(id, makeParameterFromJson(id, paramJson));
    }

    // Parameter p = parameters["AEROM_ALT_ABORT"];
    // std::cout << p.getDisplayName() << std::endl;

    return 0;
}
// It may be convenient to store the “param_type” field from the PARAM_VALUE 
//message sent by the flight controller for this parameter.
Parameter makeParameterFromJson(const string& id, const json& j) {
    // auto defines a variable containing a callable object
    // The [&] means to capture all variables from the surrounding scope by reference
    //i.e. "[]"" can see variables made outside of the function, "&" uses the original variables from outside function
    const string& type_str = "MAV_PARAM_TYPE_INT8";

    //creates a mini function with auto
    //optional<string> is a C type that can contain a string or be empty
    auto get_opt_string = [&](const string& key) -> optional<string> {
        //If the JSON object has this key, and its value is a string
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
    // 🔧 Convert string to ParameterType
    ParameterType type_enum = ParameterType::UNKNOWN;
    if (type_str == "MAV_PARAM_TYPE_INT8") type_enum = ParameterType::MAV_PARAM_TYPE_INT8;
    else if (type_str == "MAV_PARAM_TYPE_UINT8") type_enum = ParameterType::MAV_PARAM_TYPE_UINT8;
    else if (type_str == "MAV_PARAM_TYPE_REAL32") type_enum = ParameterType::MAV_PARAM_TYPE_REAL32;
    else if (type_str == "MAV_PARAM_TYPE_REAL64") type_enum = ParameterType::MAV_PARAM_TYPE_REAL64;

    // Create and return a Parameter object
    return Parameter(
        id,
        j.value("Value", 0.0f),
        type_enum,
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

