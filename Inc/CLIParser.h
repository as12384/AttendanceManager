//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_CLIPARSER_H
#define ATTENDANCEMANAGER_CLIPARSER_H
#include <string>
#include <vector>

#include "EmployeeService.h"
#include "CommandActioner.h"


class CLIParser
{
public:
    struct ParsedCommandStruct
    {
        std::string domain;
        std::string action;
        std::vector<std::string> arguments;
    }ParsedCommand;
    CLIParser(std::string commandLine);
    Handler solve();
private:
    std::string commandLine;
    ParsedCommandStruct parse();
};


#endif //ATTENDANCEMANAGER_CLIPARSER_H
