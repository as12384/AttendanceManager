//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_JSONSTORAGE_H
#define ATTENDANCEMANAGER_JSONSTORAGE_H
#include <nlohmann/json.hpp>
#include <filesystem>
#include <stdexcept>

#include "AttendanceRecord.h"
#include "Employee.h"

class JsonStorage
{
private:
    std::string filename;
public:
    JsonStorage(std::string filename);
    std::pair<std::vector<Employee>,std::vector<AttendanceRecord>> load();
    void save(const std::vector<Employee*>& employees,const std::vector<AttendanceRecord*>& attendanceRecords);
};


#endif //ATTENDANCEMANAGER_JSONSTORAGE_H
