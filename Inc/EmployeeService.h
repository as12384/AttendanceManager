//
// Created by lucas on 2026/11/8.
//

#ifndef ATTENDANCEMANAGER_EMPLOYEESERVICE_H
#define ATTENDANCEMANAGER_EMPLOYEESERVICE_H
#include "EmployeeManager.h"


class EmployeeService
{
private:
    EmployeeManager* employeeManager;
    AttendanceManager* attendanceManager;
public:
    EmployeeService();
    void addEmployee(int employeeId, std::string name, std::string department);
    void deleteEmployee(int employeeId);
    Employee* findEmployee(int employeeId);
    Employee* findEmployee(std::string name);
    void editEmployee(int employeeId, std::string newName, std::string newDepartment);
    void addAttendance(int attendanceId, string date, string checkinTime, string checkoutTime);
    void deleteAttendance(int attendanceId);
    vector<AttendanceRecord*> findAttendance(int employeeId);
    vector<AttendanceRecord*> findAttendance(std::string date);
    vector<AttendanceRecord*> listAttendance();
    void save();
};


#endif //ATTENDANCEMANAGER_EMPLOYEESERVICE_H
