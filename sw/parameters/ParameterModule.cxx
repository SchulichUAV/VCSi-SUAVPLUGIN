#include "ParameterModule.h"
#include <iostream>


ParameterModule::ParameterModule()
    : parameterManager_(std::make_unique<ParameterManager>("sw/parameters/apm.pdef.json"))
    , parameterItemModule_(std::make_unique<parameter_item_model>(parameterManager_->get_parameters())) {
    
        if (!parameterManager_->load()) {
        std::cerr << "[ParameterModule] Failed to load parameters (file missing or invalid)." << std::endl;
    } else {
        std::cout << "[ParameterModule] Parameters loaded successfully." << std::endl;
    }
}

ParameterModule::~ParameterModule() = default;

ParameterManager& ParameterModule::getManager() {
    return *parameterManager_;
}


