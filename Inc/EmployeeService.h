//
// Created by lucas on 2026/11/8.
//

#ifndef ATTENDANCEMANAGER_EMPLOYEESERVICE_H
#define ATTENDANCEMANAGER_EMPLOYEESERVICE_H
#include "EmployeeManager.h"
#include "JsonStorage.h"


class EmployeeService
{
private:

    EmployeeManager* employeeManager;
    AttendanceManager* attendanceManager;
    JsonStorage database;
public:
    EmployeeService(string filename);
    void save();
    void addEmployee(int employeeId, std::string name, std::string department);
    void deleteEmployee(int employeeId);
    const Employee* findEmployee(int employeeId);
    const std::vector<Employee*> findEmployee(std::string name);
    const vector<Employee*> listEmployees() const;
    void editEmployee(int employeeId, std::string newName, std::string newDepartment);
    void addAttendance(int attendanceId, int employeeId, int date, int checkinTime, int checkoutTime);
    void editAttendance(int attendanceId, int newCheckinTime, int newCheckoutTime);
    void deleteAttendance(int attendanceId);
    bool hasAttendance(int attendanceId);
    vector<AttendanceRecord*> findAttendanceById(int employeeId);
    vector<AttendanceRecord*> findAttendanceByDate(int date);
    vector<AttendanceRecord*> findAttendanceByDate(int dateStart, int dateEnd);
    vector<AttendanceRecord*> listAttendance();
};


#endif //ATTENDANCEMANAGER_EMPLOYEESERVICE_H
