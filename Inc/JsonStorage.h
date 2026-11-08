//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_JSONSTORAGE_H
#define ATTENDANCEMANAGER_JSONSTORAGE_H
#include <string>
#include <nlohmann/json.hpp>

#include "AttendanceRecord.h"
#include "Employee.h"

class JsonStorage
{
public:
    JsonStorage() = default;
    std::vector<AttendanceRecord> loadAttendanceRecords();
    std::vector<Employee> loadEmployees();
    void saveEmployees(std::vector<Employee> employees);
    void saveAttendance(std::vector<AttendanceRecord> attendanceRecords);
};


#endif //ATTENDANCEMANAGER_JSONSTORAGE_H
