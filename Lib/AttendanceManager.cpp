//
// Created by lucas on 2026/11/7.
//

#include "../Inc/AttendanceManager.h"

#include <ranges>

AttendanceManager::AttendanceManager(std::vector<AttendanceRecord> attendances)
{
    for (auto& record : attendances)
        this->attendances.emplace(record.id, std::move(record));
}

void AttendanceManager::addRecord(AttendanceRecord attendance)
{
    this->attendances.emplace(attendance.id, attendance);
}

void AttendanceManager::deleteRecord(int id)
{
    if (!attendances.contains(id))
        throw(std::invalid_argument("Attendance "+std::to_string(id)+" not found!!!!"));
    this->attendances.erase(id);
}

void AttendanceManager::editRecord(int id, int newCheckinTime, int newCheckoutTime)
{
    auto target = attendances.find(id);
    if (target != attendances.end())
    {
        attendances.at(id) = AttendanceRecord(id, target->second.employeeId,target->second.date, newCheckinTime, newCheckoutTime);
    }
    else
        throw(std::invalid_argument("Id does not exist"));
}

const std::vector<AttendanceRecord*> AttendanceManager::findRecordsByEmployeeId(int employeeId) const
{
    std::vector<AttendanceRecord*> result;
    for (auto& record : attendances|std::views::values|std::views::filter([employeeId](const AttendanceRecord& attendance){return attendance.employeeId == employeeId;}))
    {
        result.push_back(const_cast<AttendanceRecord*>(&record));
    }
    return result;
}

const std::vector<AttendanceRecord*> AttendanceManager::findRecordsByDate(int date)
{
    std::vector<AttendanceRecord*> result;
    for (auto& record : attendances|std::views::values|std::views::filter([date](const AttendanceRecord& attendance){return attendance.date == date;}))
    {
        result.push_back(&record);
    }
    return result;
}

const std::vector<AttendanceRecord*> AttendanceManager::findRecordsByDate(int dateStart, int dateEnd)
{
    std::vector<AttendanceRecord*> result;
    for (auto& record : attendances|std::views::values|std::views::filter([dateStart,dateEnd](const AttendanceRecord& attendance){return attendance.date >= dateStart&&attendance.date <= dateEnd;}))
    {
        result.push_back(&record);
    }
    return result;
}

vector<AttendanceRecord*> AttendanceManager::listRecords() const
{
    vector <AttendanceRecord*> result;
    for (const auto& info : attendances | views::values)
        result.push_back(const_cast<vector<AttendanceRecord*>::value_type>(&info));
    return result;
}

bool AttendanceManager::hasRecord(int id)
{
    return attendances.contains(id);
}
