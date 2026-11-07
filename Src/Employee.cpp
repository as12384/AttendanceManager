#include "Employee.h"
Employee::Employee(int number,string name,string department):number{number},name{std::move(name)},department{std::move(department)}
{
    this->number = number;
    this->name=name;
    this->department = department;
}

string Employee::getDepartment(){return department;}
string Employee::getName(){return name;}
int Employee::getNumber(){return number;}

void Employee::setDepartment(string department){this->department = department;}
void Employee::setName(string name){this->name = name;}
void Employee::setNumber(int number){this->number = number;}