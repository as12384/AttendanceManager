#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "EmployeeService.h"
#include "common/common.h"

namespace CMD
{
    bool Test(std::vector<std::string> args,EmployeeService& service)
    {
        for (const auto& arg : args)
            std::cout<<arg<<std::endl;
        throw(std::runtime_error("gugugaga!!!!!"));
        return false;
    }
    bool AddEmployee(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 3)
            throw(std::invalid_argument("Wrong Arguments count!!!"));
        int id;
        std::string name;
        std::string department;
        id = stringtoint(args[0]);
        name = args[1];
        department = args[2];
        cout<<"Creating Employee named: "<<name<<" id: "<<id<<" department: "<<department<<std::endl;
        service.addEmployee(id,name,department);
        return true;
    }
    bool FindEmployee(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 2)
        {
            throw(std::invalid_argument("FindEmployee: Wrong Arguments count!!!"));
        }
        if (args[0]=="id")
        {
            int id=stringtoint(args[1]);
            std::cout<<*(service.findEmployee(id))<<std::endl;
        }
        else if (args[0]=="name")
        {
            auto result = service.findEmployee(args[1]);
            if (result.empty())
                throw(std::invalid_argument("FindEmployee: No employee named "+args[1]+" found!!!"));
            for (auto i:result)
            {
                std::cout<<*i<<std::endl;
            }
        }
        else
            throw(std::invalid_argument("FindEmployee: Wrong Arguments!!! Should be either id or name!!!"));

        return false;
    }
    bool ListEmployees(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 0)
            throw(std::invalid_argument("ListEmployees: Wrong Arguments count!!!"));
        auto result = service.listEmployees();
        for (const auto& i : result)
            std::cout<<*i<<std::endl;
        return false;
    }
    bool EditEmployee(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 3)
            throw(std::invalid_argument("EditEmployee: Wrong Arguments count!!!"));
        int id;
        std::string name;
        std::string department;
        id = stringtoint(args[0]);
        name = args[1];
        department = args[2];
        cout<<"Edit Employee named: "<<name<<" id: "<<id<<" department: "<<department<<std::endl;
        service.editEmployee(id,name,department);
        return true;
    }
    bool DeleteEmployee(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 1)
            throw(std::invalid_argument("DeleteEmployee: Wrong Arguments!!!"));
        service.deleteEmployee(stringtoint(args[0]));
        return true;
    }
    bool AddRecord(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 4)
            throw(std::invalid_argument("AddRecord: Wrong Arguments!!!"));
        int id;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(1, 10000);
        do
        {
            id=distrib(gen);
            cout<<"trying "<<id<<" as attendance id"<<std::endl;
        }while (service.hasAttendance(id));
        service.addAttendance(id,stringtoint(args[0]),stringtoint(args[1]),stringtoint(args[2]),stringtoint(args[3]));
        return true;
    }
    bool DeleteRecord(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 1)
            throw(std::invalid_argument("DeleteRecord: Wrong Arguments!!!"));
        service.deleteAttendance(stringtoint(args[0]));
        return true;
    }
    bool EditRecord(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 3)
            throw(std::invalid_argument("EditRecord: Wrong Arguments!!!"));
        int id=stringtoint(args[0]);
        int newCheckinTime=stringtoint(args[1]);
        int newCheckoutTime=stringtoint(args[2]);
        if (newCheckinTime > newCheckoutTime)
            throw(std::invalid_argument("Checkout Time Must be greater than Checkin Time!!!"));
        service.editAttendance(id,newCheckinTime,newCheckoutTime);
        return true;
    }
    bool FindRecord(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.empty())
            throw(std::invalid_argument("FindRecord: Wrong Arguments!!!"));
        vector<AttendanceRecord*> result ;
        if (args[0]=="employee")
        {
            if (args.size() != 2)
                throw(std::invalid_argument("FindRecord: Wrong Arguments!!!"));
            result = service.findAttendanceById(stringtoint(args[1]));
        }
        else if (args[0]=="date")
        {

            if (args.size() == 2)
                result = service.findAttendanceByDate(stringtoint(args[1]));
            else if (args.size() == 3)
                result = service.findAttendanceByDate(stringtoint(args[1]),stringtoint(args[2]));
            else
                throw(std::invalid_argument("FindRecord: Wrong Arguments!!!"));
        }
        if (result.empty())
            throw(std::invalid_argument("FindRecord: No Record found!!!"));
        for (auto i:result)
            std::cout<<*i<<std::endl;
        return false;
    }
    bool ListRecords(std::vector<std::string> args,EmployeeService& service)
    {
        if (args.size() != 0)
            throw(std::invalid_argument("ListRecords: Wrong Arguments!!!"));
        auto result = service.listAttendance();
        for (auto i:result)
            std::cout<<*i<<std::endl;
        return false;
    }

}
