#include <iostream>
#include <fstream> // For file operations
#include <nlohmann/json.hpp> // For JSON parsing

using namespace std;
using json = nlohmann::json;

void static from_json(const nlohmann::json& j);

int main() {
    ifstream file("sw/apm.pdef.json");
    if (!file.is_open()) {
        std::cerr << "Error: could not open apm.pdef.json" << std::endl;
        return 1;  // or handle differently
    }
    json data;
    try {
        file >> data; // Use the stream operator to parse
    } catch (const json::parse_error& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

void static from_json(const nlohmann::json& j) {
        
}
