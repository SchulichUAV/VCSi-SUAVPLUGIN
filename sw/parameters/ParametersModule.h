#pragma once

#include "param_utils.h"
#include <memory>

class ParametersModule {
public:
    ParametersModule();
    ~ParametersModule();

    // Accessor to the manager
    ParameterManager& getManager();

private:
    std::unique_ptr<ParameterManager> parameterManager_;
};
