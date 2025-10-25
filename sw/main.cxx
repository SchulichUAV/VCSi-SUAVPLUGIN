// main.cxx
#include <iostream>

#ifdef HELLO_WORLD_EXPORTS
#define HELLO_WORLD_API __declspec(dllexport)
#else
#define HELLO_WORLD_API __declspec(dllimport)
#endif

// Example exported function
extern "C" HELLO_WORLD_API void say_hello()
{
    std::cout << "Hello from DLL!" << std::endl;
}


// plugincontent
// {
//     parametercontainer{
//         domain
//         view
//         qml
//     }
//     featureXcontainer
//     {
//     }
// }
