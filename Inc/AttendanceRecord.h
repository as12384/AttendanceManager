
#ifndef ATTENDANCEMANAGER_ATTENDENCERECODE_H
#define ATTENDANCEMANAGER_ATTENDENCERECODE_H
#include <string>

class AttendanceRecord
{
    private:
    int id;
    std::string date;
    std::string checkinTime;
    std::string checkoutTime;
    public:
    AttendanceRecord(int id,std::string name,std::string checkinTime,std::string checkoutTime);;
};


#endif //ATTENDANCEMANAGER_ATTENDENCERECODE_H
