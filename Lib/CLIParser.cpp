//
// Created by lucas on 2026/11/7.
//

#include "CLIParser.h"
#include "CommandActioner.h"

#include <sstream>
#include <utility>
#include <iterator>

#include "EmployeeService.h"

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

    if (it != end)
        result.domain = *it++;
    else
        throw(std::invalid_argument("NoInput!"));


    if (it != end)
        result.action = *it++;
    else
        throw(std::invalid_argument("Have Domain but No Action!"));

    result.arguments=vector<std::string>{it,end};

    return result;
}

Handler CLIParser::solve()
{
    std::tuple<std::string,std::string,Handler> JumpMap[]
    {
        {"gugu","gaga",&CMD::Test},
        {"employee","add",&CMD::AddEmployee},           //<employeeId> <name> <department>
        {"employee","delete",&CMD::DeleteEmployee},     //<employeeId>
        {"employee","edit",&CMD::EditEmployee},         //<employeeId> <newName> <newDepartment>
        {"employee","find",&CMD::FindEmployee},         //id <employeeId> / name <name>
        {"employee","list",&CMD::ListEmployees},        //
        {"attendance","add",&CMD::AddRecord},           //<employeeId> <date> <checkin> <checkout>
        {"attendance","delete",&CMD::DeleteRecord},     //<attendanceId>
        {"attendance","edit",&CMD::EditRecord},         //<attendanceId> <newCheckin> <newCheckout>
        {"attendance","find",&CMD::FindRecord},         //employee <employeeId> / date <date>/<startDate> <endDate>
        {"attendance","list",&CMD::ListRecords},        //
    };
    for (const auto& [domain,action,handler] : JumpMap)
    {
        if (domain == ParsedCommand.domain&&action==ParsedCommand.action)
        {
            return handler;
        }
    }
    throw(std::invalid_argument("Command not found!"));
}
