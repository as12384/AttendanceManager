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

public:
    EmployeeManager(std::vector<Employee> employees);
    ~EmployeeManager();
    void addEmployee(Employee employee);
    void deleteEmployee(int employeeId);
    Employee* findEmployee(int employeeId);
    const std::vector<Employee*> findEmployee(std::string name) const;
    const std::vector<Employee*> listEmployees() const;
    void editEmployee(int employee_id, const string& name, const std::string& department);
};


#endif //ATTENDANCEMANAGER_EMPLOYEEMANAGER_H
