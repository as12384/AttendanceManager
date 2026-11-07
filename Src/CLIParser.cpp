//
// Created by lucas on 2026/11/7.
//

#include "CLIParser.h"
#include "CommandActioner.h"

#include <sstream>
#include <utility>
#include <iterator>

CLIParser::CLIParser(std::string commandLine)
    : commandLine(std::move(commandLine))
{
    ParsedCommand = parse();
}

CLIParser::ParsedCommandStruct CLIParser::parse()
{
    ParsedCommandStruct result;
    std::istringstream ss(commandLine);
    std::istream_iterator<std::string> it(ss);
    const std::istream_iterator<std::string> end;

    if (it == end)
        throw(std::invalid_argument("NoInput!"));

    result.commandName = *it++;
    while (it != end)
        result.arguments.push_back(*it++);

    return result;
}

void CLIParser::run()
{
    using Handler = void (*)(std::vector<std::string>);
    std::pair<std::string,Handler> JumpMap[]
    {
        {"gugu",&CMD::Test},
    };
    for (const auto& [command,handler] : JumpMap)
    {
        if (command == ParsedCommand.commandName)
            handler(ParsedCommand.arguments);
    }
}
