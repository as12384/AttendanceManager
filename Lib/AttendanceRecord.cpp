//
// Created by lucas on 2026/11/6.
//

#include <utility>

#include "../Inc/AttendanceRecord.h"

AttendanceRecord::AttendanceRecord(int id,int employeeId, int date, int checkinTime, int checkoutTime):id(id),employeeId(employeeId), date(date), checkinTime(checkinTime), checkoutTime(checkoutTime)
{
}
std::ostream& operator<<(std::ostream& os, const AttendanceRecord& record)
{
    return os << "AttendanceRecord{id=" << record.id
              << ", employee=" << record.employeeId
              << ", date=" << record.date <<
                  ", checkinTime=" << record.checkinTime
                << ", checkoutTime=" << record.checkoutTime<<"}";
}