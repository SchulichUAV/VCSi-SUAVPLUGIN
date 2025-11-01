#pragma once

#include "param_utils.h"
#include <memory>

class ParameterModule {
public:
    ParameterModule();
    ~ParameterModule();

    ParameterManager& getManager();

private:
    std::unique_ptr<ParameterManager> parameterManager_;
};
