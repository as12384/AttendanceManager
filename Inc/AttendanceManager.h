//
// Created by lucas on 2026/11/7.
//

#ifndef ATTENDANCEMANAGER_ATTENDANCEMANAGER_H
#define ATTENDANCEMANAGER_ATTENDANCEMANAGER_H
#include <map>
#include <vector>

#include "AttendanceRecord.h"


class AttendanceManager
{
    private:
    std::map<int,AttendanceRecord> attendances;
    public:
    AttendanceManager(std::vector<AttendanceRecord> attendances);
    void addRecord(AttendanceRecord attendance);
    void deleteRecord(int id);
    void editRecord(int id, int newCheckinTime, int newCheckoutTime);
    const std::vector<AttendanceRecord*> findRecordsByEmployeeId(int employeeId) const;
    const std::vector<AttendanceRecord*> findRecordsByDate(int date);
    const std::vector<AttendanceRecord*> findRecordsByDate(int dateStart, int dateEnd);
    std::vector<AttendanceRecord*> listRecords() const;
    bool hasRecord(int id);
};


#endif //ATTENDANCEMANAGER_ATTENDANCEMANAGER_H
