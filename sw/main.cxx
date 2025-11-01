#include "parameters/ParameterModule.h"

int main() {
    ParameterModule parameterModule;

    auto& manager = parameterModule.getManager();
    manager.print_parameters();

    return 0;
}
