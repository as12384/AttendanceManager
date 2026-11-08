#ifndef ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
#define ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
#include <map>
#include <set>

#include "AttendanceManager.h"
#include "Employee.h"
using namespace std;

class EmployeeManager
{
private:
    map<int,Employee> employees;
    void loadEmployees(std::string filename);
    void saveEmployees();

public:
    EmployeeManager(std::vector<Employee> employees);
    ~EmployeeManager();
    void addEmployee(Employee employee);
    void deleteEmployee(int employeeId);
    Employee* findEmployee(int employeeId);
    const map<int,Employee>& listEmployees() const;
};


#endif //ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
