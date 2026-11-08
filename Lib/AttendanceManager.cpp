//
// Created by lucas on 2026/11/7.
//

#include "../Inc/AttendanceManager.h"

AttendanceManager::AttendanceManager(std::vector<AttendanceRecord> attendances)
{
}

const std::map<int, AttendanceRecord>& AttendanceManager::getAttendances() const
{
    return attendances;
}
