
#ifndef ATTENDANCEMANAGER_ATTENDENCERECODE_H
#define ATTENDANCEMANAGER_ATTENDENCERECODE_H
#include "Employee.h"


class AttendanceRecord
{
    private:
    Employee* employee;
    int id;
    int checkinTime;
    int checkoutTime;
    public:
    AttendanceRecord(int id,string name,int checkinTime,int checkoutTime);;
};


#endif //ATTENDANCEMANAGER_ATTENDENCERECODE_H
