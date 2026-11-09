#ifndef ATTENDANCEMANAGER_EMPLOYEE_H
#define ATTENDANCEMANAGER_EMPLOYEE_H
#include <string>
#include <ostream>


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

std::ostream& operator<<(std::ostream& os, const Employee& employee);

#endif //ATTENDANCEMANAGER_EMPLOYEE_H
