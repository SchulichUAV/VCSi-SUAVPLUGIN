#include "parameters/ParametersModule.h"

int main() {
    ParametersModule parametersModule;

    auto& manager = parametersModule.getManager();
    manager.print_parameters();

    return 0;
}
