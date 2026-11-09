#include "Employee.h"

Employee::Employee(int id,string name,string department):id{id},name{std::move(name)},department{std::move(department)}
{}


bool Employee::operator==(const Employee& other) const
{
    return this->id == other.id;
}

bool Employee::operator<(const Employee& other) const
{
    return this->id < other.id;
}

std::ostream& operator<<(std::ostream& os, const Employee& e)
{
    return os << "Employee{id=" << e.id
              << ", name=" << e.name
              << ", department=" << e.department << "}";
}