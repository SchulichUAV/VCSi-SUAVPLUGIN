#pragma once

#include "param_utils.h"
#include <memory>
#include "parameter_item_model.h"

class ParameterModule {
public:
    ParameterModule();
    ~ParameterModule();


    ParameterManager& getManager();

private:
    std::unique_ptr<ParameterManager> parameterManager_;
    std::unique_ptr<parameter_item_model> parameterItemModule_;

};
