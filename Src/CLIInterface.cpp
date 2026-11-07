//
// Created by lucas on 2026/11/7.
//

#include "../Inc/CLIInterface.h"

#include <iostream>

#include "CLIParser.h"

CLIInterface::CLIInterface()
= default;

void CLIInterface::start()
{
    std::getline(std::cin, commandLine);
    try
    {
        CLIParser parser{commandLine};
        parser.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
