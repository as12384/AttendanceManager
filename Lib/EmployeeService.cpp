//
// Created by lucas on 2026/11/8.
//

#include "../Inc/EmployeeService.h"

#include "JsonStorage.h"

EmployeeService::EmployeeService()
{
    JsonStorage database;
    employeeManager = new EmployeeManager(database.loadEmployees());
    attendanceManager = new AttendanceManager(database.loadAttendanceRecords());
}

void EmployeeService::save()
{
}
