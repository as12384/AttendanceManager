#ifndef ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
#define ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
#include <set>

#include "Employee.h"
using namespace std;

class EmployeeManager
{
    private:
    set<Employee> employees;
    public:
    EmployeeManager();
    
};


#endif //ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
