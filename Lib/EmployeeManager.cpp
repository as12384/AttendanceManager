//
// Created by lucas on 2026/11/6.
//

#include "EmployeeManager.h"

#include <iostream>
#include <ostream>
#include <ranges>
#include <utility>

EmployeeManager::EmployeeManager(std::vector<Employee> employees)
{
    for (auto& employee: employees)
        this->employees.emplace(employee.id,employee);
}

EmployeeManager::~EmployeeManager()
= default;

void EmployeeManager::addEmployee(Employee employee)
{
    if (employees.contains(employee.id))
        throw(std::invalid_argument("Employee "+employee.name+" already exists!!!!"));
    employees.emplace(employee.id,employee);
}

void EmployeeManager::deleteEmployee(int employeeId)
{
    if (!employees.contains(employeeId))
        throw(std::invalid_argument("Employee "+std::to_string(employeeId)+" not found!!!!"));
    employees.erase(employeeId);
}
Employee* EmployeeManager::findEmployee(int employeeId)
{
    for (auto& [id,employee]: employees)
        if (id == employeeId)
            return &employee;
    throw(std::invalid_argument("Employee not found!!!!!"));
}

const std::vector<Employee*> EmployeeManager::findEmployee(std::string name) const
{
    vector<Employee*> result;
    for (auto& employee: employees|std::views::values|std::views::filter([name](auto employees){return employees.name == name;}))
    {
        result.push_back(const_cast<vector<Employee*>::value_type>(&employee));
    }
    return result;
}


const std::vector<Employee*> EmployeeManager::listEmployees() const
{
    std::vector<Employee*> result;
    result.reserve(employees.size());

    for (const auto& employee : employees|std::views::values)
        result.push_back(const_cast<vector<Employee*>::value_type>(&employee));

    return result;
}

void EmployeeManager::editEmployee(int employee_id, const string& name, const std::string& department)
{
    auto employee_to_edit =findEmployee(employee_id);
    employee_to_edit->name = name;
    employee_to_edit->department = department;
}
