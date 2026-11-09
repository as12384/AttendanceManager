//
// Created by lucas on 2026/11/7.
//

#include "../Inc/CLIInterface.h"

#include <iostream>

#include "CLIParser.h"
#include "EmployeeManager.h"


CLIInterface::CLIInterface(EmployeeService &manager) : service(manager)
{}


void CLIInterface::start()
{
    while (true)
    {
        std::cout << ">> " ;

        if (!std::getline(std::cin, commandLine))
            break;

        if (commandLine == "quit")
            break;

        try
        {
            CLIParser parser{commandLine};
            Handler funcPtr=parser.solve();
            if (funcPtr(parser.ParsedCommand.arguments,service))
                service.save();
        }
        catch (const std::exception& e)
        {
            std::cout <<"ERROR: "<< e.what() << '\n';
        }
    }
}
