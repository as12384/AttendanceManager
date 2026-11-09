//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_COMMANDACTIONER_H
#define ATTENDANCEMANAGER_COMMANDACTIONER_H
#include <string>
#include <vector>

using Handler = bool (*)(std::vector<std::string>,EmployeeService& service);

namespace CMD
{
    bool Test(std::vector<std::string>,EmployeeService& service);
    bool AddEmployee(std::vector<std::string>,EmployeeService& service);
    bool FindEmployee(std::vector<std::string> args,EmployeeService& service);
    bool ListEmployees(std::vector<std::string> args,EmployeeService& service);
    bool EditEmployee(std::vector<std::string> args,EmployeeService& service);
    bool DeleteEmployee(std::vector<std::string> args,EmployeeService& service);
    bool AddRecord(std::vector<std::string> args,EmployeeService& service);
    bool DeleteRecord(std::vector<std::string> args,EmployeeService& service);
    bool EditRecord(std::vector<std::string> args,EmployeeService& service);
    bool FindRecord(std::vector<std::string> args,EmployeeService& service);
    bool ListRecords(std::vector<std::string> args,EmployeeService& service);
}
#endif //ATTENDANCEMANAGER_COMMANDACTIONER_H
