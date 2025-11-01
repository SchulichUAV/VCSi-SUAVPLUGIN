#include "parameters/param_utils.h"

int main() {
    ParameterManager pm;
    if (pm.load()) {
        pm.print_parameters();
    }
}