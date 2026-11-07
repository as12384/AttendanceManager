#ifndef ATTENDANCEMANAGER_EMPLOYEE_H
#define ATTENDANCEMANAGER_EMPLOYEE_H
#include <string>
using namespace std;
class Employee
{
    private:
    string name;
    string department;
    int number;

    public:
    Employee(int number,string name,string department);
    string getName();
    string getDepartment();
    int getNumber();
    void setName(string name);
    void setDepartment(string department);
    void setNumber(int number);
    bool operator==(const Employee&) const;

};


#endif //ATTENDANCEMANAGER_EMPLOYEE_H
