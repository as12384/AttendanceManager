//
// Created by lucas on 2026/11/7.
//

#include "../Inc/CLIInterface.h"

#include <iostream>

#include "CLIParser.h"
#include "EmployeeManager.h"


CLIInterface::CLIInterface(EmployeeService &manager) : service(manager)
{
    this->service=manager;
}


void CLIInterface::start()
{
    while (std::getline(std::cin, commandLine))
    {
        try
        {
            CLIParser parser{commandLine};
            parser.run();
            service.save();
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
