//
// Created by lucas on 2026/11/7.
//

#include "../Inc/JsonStorage.h"

#include <fstream>
#include <iostream>
#include <utility>

using namespace nlohmann;
namespace
{
    json toJson(const Employee& e)
    {
        return {
            {"id", e.id},
            {"name", e.name},
            {"department", e.department}
        };
    }

    Employee employeeFromJson(const json& j)
    {
        return Employee{
            j.at("id").get<int>(),
            j.at("name").get<std::string>(),
            j.at("department").get<std::string>()
        };
    }

    json toJson(const AttendanceRecord& r)
    {
        return {
            {"id", r.id},
                {"employeeId", r.employeeId},
            {"date", r.date},
            {"checkin", r.checkinTime},
            {"checkout", r.checkoutTime}
        };
    }

    AttendanceRecord attendanceFromJson(const json& j)
    {
        return AttendanceRecord{
            j.at("id").get<int>(),
            j.at("employeeId").get<int>(),
            j.at("date").get<int>(),
            j.at("checkin").get<int>(),
            j.at("checkout").get<int>()
        };
    }
}


using json = nlohmann::json;

JsonStorage::JsonStorage(std::string filename):filename(std::move(filename))
{}

std::pair<std::vector<Employee>, std::vector<AttendanceRecord>> JsonStorage::load()
{
    std::cout<<"Trying to Load "<<filename<<std::endl;
    std::ifstream in(filename);
    if (!in)
        return {};

    json j;
    in >> j;

    std::vector<Employee> employees;
    std::vector<AttendanceRecord> attendances;

    for (const auto& item : j.value("employees", json::array()))
        employees.push_back(employeeFromJson(item));

    for (const auto& item : j.value("attendance", json::array()))
        attendances.push_back(attendanceFromJson(item));

    return make_pair(employees, attendances);
}

void JsonStorage::save(const std::vector<Employee*>& employees, const std::vector<AttendanceRecord*>& attendanceRecords)
{
    std::cout<<"Trying to Save "<<filename<<std::endl;
    json j;
    j["employees"] = json::array();
    j["attendance"] = json::array();

    for (const auto& e : employees)
        j["employees"].push_back(toJson(*e));

    for (const auto& r : attendanceRecords)
        j["attendance"].push_back(toJson(*r));

    std::string tmp = filename;
    tmp += ".tmp";

    {
        std::ofstream out(tmp);
        if (!out)
            throw std::runtime_error("cannot open " + tmp);

        out << j.dump(2);
        if (!out)
            throw std::runtime_error("write failed");
    }

    std::filesystem::rename(tmp, filename);
}