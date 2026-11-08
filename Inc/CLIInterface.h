//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_CLIINTERFACE_H
#define ATTENDANCEMANAGER_CLIINTERFACE_H
#include <string>
#include <vector>

#include "EmployeeService.h"

class CLIInterface
{
private:
    std::string commandLine;
    EmployeeService &service;
public:
    CLIInterface(EmployeeService &manager);
    void start();
};


#endif //ATTENDANCEMANAGER_CLIINTERFACE_H
