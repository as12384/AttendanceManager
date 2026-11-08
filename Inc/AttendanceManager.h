//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_ATTENDANCEMANAGER_H
#define ATTENDANCEMANAGER_ATTENDANCEMANAGER_H
#include <map>
#include <vector>

#include "AttendanceRecord.h"
#include "Employee.h"


class AttendanceManager
{
    private:
    std::map<int,AttendanceRecord> attendances;
    public:
    AttendanceManager(std::vector<AttendanceRecord> attendances);
    void deleteRecord(int id);
    const std::map<int,AttendanceRecord>& getAttendances() const;
};


#endif //ATTENDANCEMANAGER_ATTENDANCEMANAGER_H
