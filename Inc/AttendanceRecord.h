
#ifndef ATTENDANCEMANAGER_ATTENDENCERECODE_H
#define ATTENDANCEMANAGER_ATTENDENCERECODE_H
#include <string>

#include "Employee.h"

class AttendanceRecord
{
    public:
    AttendanceRecord(int id,int employeeId,int date,int checkinTime,int checkoutTime);;
    int id;
    int date;
    int checkinTime;
    int checkoutTime;
    int employeeId;
};
std::ostream& operator<<(std::ostream& os, const AttendanceRecord& record);


#endif //ATTENDANCEMANAGER_ATTENDENCERECODE_H
