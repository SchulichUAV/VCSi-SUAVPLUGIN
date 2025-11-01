#pragma once

#include "param_utils.h"
#include <memory>

class ParametersModule {
public:
    ParametersModule();
    ~ParametersModule();

    ParameterManager& getManager();

private:
    std::unique_ptr<ParameterManager> parameterManager_;
};
