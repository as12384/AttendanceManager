#include <iostream>
#include <stdexcept>

#include <catch2/catch_test_macros.hpp>

#include "CLIParser.h"
#include "Employee.h"
#include "EmployeeManager.h"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_exception.hpp"
#include "common/TimeStampConvent.h"

TEST_CASE("TimeStamp Conversion", "[timeStampConversion]")
{
    auto result1 = TimetoStamp("2026-8-15 09:00:00","%Y-%m-%d %H:%M:%S");
    REQUIRE(result1==1786784400);
    auto result2 = TimetoStamp("2026-8-15   ","%Y-%m-%d");
    REQUIRE(result2==1786752000);
    REQUIRE_THROWS_MATCHES(TimetoStamp("2026-8-15 sjDFKaicol 09:00:00","%Y-%m-%d %H:%M:%S"),std::invalid_argument, Catch::Matchers::Message("Format Parsing Failed"));
}

TEST_CASE("CommandLine Parsing","[CLI]")
{
    CLIParser parser1{"gugu gaga1 gaga2 ladygaga"};
    REQUIRE(parser1.ParsedCommand.commandName=="gugu");
    REQUIRE(parser1.ParsedCommand.arguments.size()==3);
    REQUIRE(parser1.ParsedCommand.arguments==std::vector<std::string>{"gaga1","gaga2","ladygaga"});
    REQUIRE_THROWS_MATCHES(CLIParser{""}, std::invalid_argument,
                           Catch::Matchers::Message("NoInput!"));
    REQUIRE_THROWS_MATCHES(CLIParser{"   "}, std::invalid_argument,
                       Catch::Matchers::Message("NoInput!"));
    REQUIRE_THROWS_MATCHES(parser1.run(), std::runtime_error,Catch::Matchers::Message("gugugaga!!!!!"));
}

TEST_CASE("Test Employee Basic","[Employee]")
{
    Employee employee1{42,"tomori","mygo"};
    REQUIRE(employee1.id==42);
    REQUIRE(employee1.name=="tomori");
    REQUIRE(employee1.department=="mygo");
}

TEST_CASE("Test EmployeeManager","[EmployeeManager]")
{
    vector<Employee> employees;
    employees.emplace_back(42,"tomori","mygo");
    employees.emplace_back(43,"anno","mygo");
    employees.emplace_back(44,"riki","mygo");
    EmployeeManager employeeManager{employees};
    REQUIRE(*employeeManager.findEmployee(42)==Employee{42,"tomori","mygo"});
    employeeManager.addEmployee(Employee{45,"soyo","mygo"});
    employeeManager.addEmployee(Employee{46,"rana","mygo"});
    REQUIRE(*employeeManager.findEmployee(45)==Employee{45,"soyo","mygo"});
    employeeManager.deleteEmployee(42);
    REQUIRE_THROWS_MATCHES(employeeManager.findEmployee(42),std::invalid_argument,Catch::Matchers::Message("Employee not found!!!!!"));
    REQUIRE_THROWS_MATCHES(employeeManager.addEmployee(Employee{45,"soyo","mygo"}),std::invalid_argument,Catch::Matchers::Message("Employee soyo already exists!!!!"));
}