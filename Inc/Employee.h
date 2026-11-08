#ifndef ATTENDANCEMANAGER_EMPLOYEE_H
#define ATTENDANCEMANAGER_EMPLOYEE_H
#include <string>
#include <text_encoding>

#include "AttendanceManager.h"

using namespace std;
class Employee
{
public:
    string name;
    string department;
    int id;
    Employee(int id,string name,string department);
    bool operator==(const Employee& other) const;
    bool operator<(const Employee& other) const;
};


#endif //ATTENDANCEMANAGER_EMPLOYEE_H
