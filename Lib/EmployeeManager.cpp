//
// Created by lucas on 2026/11/6.
//

#include "EmployeeManager.h"

#include <iostream>
#include <ostream>
#include <utility>
void EmployeeManager::saveEmployees()
{
    std::cout<<"Tried to save employees!!!"<<std::endl;
}

EmployeeManager::EmployeeManager(std::vector<Employee> employees)
{
    for (auto& employee: employees)
        this->employees.emplace(employee.id,employee);
}

EmployeeManager::~EmployeeManager()
{
}

void EmployeeManager::addEmployee(Employee employee)
{
    if (employees.contains(employee.id))
        throw(std::invalid_argument("Employee "+employee.name+" already exists!!!!"));
    employees.emplace(employee.id,employee);
}

void EmployeeManager::deleteEmployee(int employeeId)
{
    employees.erase(employeeId);
}

Employee* EmployeeManager::findEmployee(int employeeId)
{
    for (auto& [id,employee]: employees)
        if (id == employeeId)
            return &employee;
    throw(std::invalid_argument("Employee not found!!!!!"));
}
