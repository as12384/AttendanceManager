//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_CLIPARSER_H
#define ATTENDANCEMANAGER_CLIPARSER_H
#include <string>
#include <vector>


class CLIParser
{
public:
    struct ParsedCommandStruct
    {
        std::string commandName;
        std::vector<std::string> arguments;
    }ParsedCommand;
    CLIParser(std::string commandLine);
    void run();
private:
    std::string commandLine;
    ParsedCommandStruct parse();
};


#endif //ATTENDANCEMANAGER_CLIPARSER_H
