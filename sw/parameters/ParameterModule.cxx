#include "ParametersModule.h"

ParametersModule::ParametersModule()
    : parameterManager_(std::make_unique<ParameterManager>("sw/parameters/apm.pdef.json"))
{
    // Load parameters when the module initializes
    if (!parameterManager_->load()) {
        std::cerr << "[ParametersModule] Failed to load parameters." << std::endl;
    } else {
        std::cout << "[ParametersModule] Parameters loaded successfully." << std::endl;
    }
}

ParametersModule::~ParametersModule() = default;

ParameterManager& ParametersModule::getManager() {
    return *parameterManager_;
}
