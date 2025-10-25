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
        file >> data; 
    } catch (const json::parse_error& e) {
        cerr << "Error parsing JSON: " << e.what() <<   endl;
        return 1;
    }

    std::vector<Parameter> parameters;
    
    json root;
    std::string category;
    for (auto& [category, param] : data.items()) {
        if (category == "json") {
             continue;
        }
        // cout << param;
        for (auto& [key, value] : data[category].items()) {
            parameters.push_back(makeParameterFromJson(key, value));
        }
        
    }

    for( int i = 0; i < parameters.size(); i++) {
        cout << parameters[i].getId() + ": " + parameters[i].getDisplayName() << endl;
        
    }
    cout << parameters.size();


    return 0;
}
// It may be convenient to store the “param_type” field from the PARAM_VALUE 
//message sent by the flight controller for this parameter.
Parameter makeParameterFromJson(const string& id, const json& j) {
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
        if (j.contains(key) && j[key].is_boolean())
            return j[key].get<bool>();
        return nullopt;
    };

    auto get_opt_float = [&](const string& key) -> optional<float> {
        if (j.contains(key) && j[key].is_number())
            return j[key].get<float>();
        return nullopt;
    };
    auto get_opt_int = [&](const string& key) -> optional<int> {
        if (j.contains(key) && j[key].is_number())
            return j[key].get<int>();
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
        get_opt_int("Callibration"),
        values,
        bitmask,
        range
    );
}

