//
// Created by lucas on 2026/11/8.
//

#include <utility>

#include "../Inc/EmployeeService.h"

#include <iostream>

#include "JsonStorage.h"

EmployeeService::EmployeeService(std::string filename) : database(std::move(filename))
{
    auto [employees, attendances] = database.load();

    employeeManager = new EmployeeManager(std::move(employees));
    attendanceManager = new AttendanceManager(std::move(attendances));
}

void EmployeeService::save()
{
    database.save(employeeManager->listEmployees(),attendanceManager->listRecords());
}

void EmployeeService::addEmployee(int employeeId, std::string name, std::string department)
{
    employeeManager->addEmployee(Employee{employeeId, name, department});
}

void EmployeeService::deleteEmployee(int employeeId)
{
    employeeManager->deleteEmployee(employeeId);
}

const Employee* EmployeeService::findEmployee(int employeeId)
{
    return employeeManager->findEmployee(employeeId);
}

const std::vector<Employee*> EmployeeService::findEmployee(std::string name)
{
    return employeeManager->findEmployee(std::move(name));
}

const vector<Employee*> EmployeeService::listEmployees() const
{
    return employeeManager->listEmployees();
}

void EmployeeService::editEmployee(int employeeId, std::string newName, std::string newDepartment)
{
    employeeManager->editEmployee(employeeId, newName, newDepartment);
}

void EmployeeService::addAttendance(int attendanceId, int employeeId, int date, int checkinTime, int checkoutTime)
{
    employeeManager->findEmployee(employeeId);
    attendanceManager->addRecord(AttendanceRecord{attendanceId, employeeId, date, checkinTime, checkoutTime});
}

void EmployeeService::editAttendance(int attendanceId, int newCheckinTime, int newCheckoutTime)
{
    attendanceManager->editRecord(attendanceId, newCheckinTime, newCheckoutTime);
}

void EmployeeService::deleteAttendance(int attendanceId)
{
    attendanceManager->deleteRecord(attendanceId);
}

bool EmployeeService::hasAttendance(int attendanceId)
{
    return attendanceManager->hasRecord(attendanceId);
}

vector<AttendanceRecord*> EmployeeService::findAttendanceById(int employeeId)
{
    return attendanceManager->findRecordsByEmployeeId(employeeId);
}

vector<AttendanceRecord*> EmployeeService::findAttendanceByDate(int date)
{
    return attendanceManager->findRecordsByDate(date);
}

vector<AttendanceRecord*> EmployeeService::findAttendanceByDate(int dateStart, int dateEnd)
{
    return attendanceManager->findRecordsByDate(dateStart, dateEnd);
}

vector<AttendanceRecord*> EmployeeService::listAttendance()
{
    return attendanceManager->listRecords();
}

