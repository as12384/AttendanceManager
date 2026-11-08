#include <iostream>
#include <chrono>
#include <sstream>

#include "CLIInterface.h"
#include "EmployeeManager.h"
#include "EmployeeService.h"

int main() {
    try
    {
        EmployeeService manager;
        CLIInterface cli(manager);
        cli.start();
    }
    catch (std::exception& e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}
