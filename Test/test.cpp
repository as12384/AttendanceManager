#include <iostream>
#include <stdexcept>

#include <catch2/catch_test_macros.hpp>

#include "AttendanceManager.h"
#include "AttendanceRecord.h"
#include "CLIParser.h"
#include "Employee.h"
#include "EmployeeManager.h"
#include "EmployeeService.h"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_exception.hpp"
#include "common/common.h"

TEST_CASE("TimeStamp Conversion", "[timeStampConversion]")
{
    auto result1 = TimetoStamp("2026-8-15 09:00:00","%Y-%m-%d %H:%M:%S");
    REQUIRE(result1==1786784400);
    auto result2 = TimetoStamp("2026-8-15   ","%Y-%m-%d");
    REQUIRE(result2==1786752000);
    REQUIRE_THROWS_MATCHES(TimetoStamp("2026-8-15 sjDFKaicol 09:00:00","%Y-%m-%d %H:%M:%S"),std::invalid_argument, Catch::Matchers::Message("Format Parsing Failed"));
}

TEST_CASE("String to int", "[stringtoint]")
{
    REQUIRE(stringtoint("0") == 0);
    REQUIRE(stringtoint("7") == 7);
    REQUIRE(stringtoint("42") == 42);
    REQUIRE(stringtoint("0012") == 12);
    REQUIRE(stringtoint("12345") == 12345);

    REQUIRE_THROWS_MATCHES(
        stringtoint("12a"),
        std::invalid_argument,
        Catch::Matchers::Message("12a is expected to be a number!!!"));

    REQUIRE_THROWS_MATCHES(
        stringtoint("4 2"),
        std::invalid_argument,
        Catch::Matchers::Message("4 2 is expected to be a number!!!"));
}

TEST_CASE("CommandLine Parsing","[CLI]")
{
    CLIParser parser1{"gugu gaga gugugaga ladygaga"};
    REQUIRE(parser1.ParsedCommand.domain=="gugu");
    REQUIRE(parser1.ParsedCommand.action=="gaga");

    REQUIRE(parser1.ParsedCommand.arguments.size()==2);
    REQUIRE(parser1.ParsedCommand.arguments==std::vector<std::string>{"gugugaga","ladygaga"});
    REQUIRE_THROWS_MATCHES(CLIParser{""}, std::invalid_argument,
                           Catch::Matchers::Message("NoInput!"));
    REQUIRE_THROWS_MATCHES(CLIParser{"   "}, std::invalid_argument,
                       Catch::Matchers::Message("NoInput!"));
    EmployeeService service{"test_database.json"};
    Handler handler = parser1.solve();

    REQUIRE_THROWS_MATCHES(
        handler(parser1.ParsedCommand.arguments, service),
        std::runtime_error,
        Catch::Matchers::Message("gugugaga!!!!!"));
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
    vector<Employee> bandMember;
    bandMember.emplace_back(42,"tomori","mygo");
    bandMember.emplace_back(43,"anno","mygo");
    bandMember.emplace_back(44,"riki","mygo");
    EmployeeManager employeeManager{bandMember};
    REQUIRE(*employeeManager.findEmployee(42)==Employee{42,"tomori","mygo"});
    employeeManager.addEmployee(Employee{45,"soyo","mygo"});
    bandMember.emplace_back(45,"soyo","mygo");
    employeeManager.addEmployee(Employee{46,"rana","mygo"});
    bandMember.emplace_back(46,"rana","mygo");
    REQUIRE(*employeeManager.findEmployee(45)==Employee{45,"soyo","mygo"});
    employeeManager.deleteEmployee(42);
    bandMember.erase(bandMember.begin());
    REQUIRE_THROWS_MATCHES(employeeManager.findEmployee(42),std::invalid_argument,Catch::Matchers::Message("Employee not found!!!!!"));
    REQUIRE_THROWS_MATCHES(employeeManager.addEmployee(Employee{45,"soyo","mygo"}),std::invalid_argument,Catch::Matchers::Message("Employee soyo already exists!!!!"));

}

TEST_CASE("Test AttendanceManager", "[AttendanceManager]")
{
    std::vector<AttendanceRecord> records{
        {1, 42, 20261109, 900, 1800},
        {2, 42, 20261110, 830, 1730},
        {3, 43, 20261109, 1000, 1900}
    };

    AttendanceManager manager{records};

    SECTION("find records by employee id")
    {
        const auto result = manager.findRecordsByEmployeeId(42);

        REQUIRE(result.size() == 2);
        REQUIRE(result[0]->id == 1);
        REQUIRE(result[0]->employeeId == 42);
        REQUIRE(result[1]->id == 2);
        REQUIRE(result[1]->employeeId == 42);
    }

    SECTION("find records by exact date")
    {
        const auto result = manager.findRecordsByDate(20261109);

        REQUIRE(result.size() == 2);
        REQUIRE(result[0]->id == 1);
        REQUIRE(result[0]->date == 20261109);
        REQUIRE(result[1]->id == 3);
        REQUIRE(result[1]->date == 20261109);
    }

    SECTION("find records by date range")
    {
        const auto result = manager.findRecordsByDate(20261109, 20261110);

        REQUIRE(result.size() == 3);
        REQUIRE(result[0]->id == 1);
        REQUIRE(result[1]->id == 2);
        REQUIRE(result[2]->id == 3);
    }

    SECTION("find records by unknown employee id")
    {
        const auto result = manager.findRecordsByEmployeeId(999);

        REQUIRE(result.empty());
    }

    SECTION("find records by unknown date")
    {
        const auto result = manager.findRecordsByDate(20261231);

        REQUIRE(result.empty());
    }

    SECTION("add record")
    {
        manager.addRecord(AttendanceRecord{4, 44, 20261111, 800, 1700});

        const auto result = manager.findRecordsByEmployeeId(44);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0]->id == 4);
        REQUIRE(result[0]->date == 20261111);
        REQUIRE(result[0]->checkinTime == 800);
        REQUIRE(result[0]->checkoutTime == 1700);
    }

    SECTION("delete record")
    {
        manager.deleteRecord(1);

        const auto result = manager.findRecordsByEmployeeId(42);

        REQUIRE(result.size() == 1);
        REQUIRE(result[0]->id == 2);
    }

    SECTION("edit record")
    {
        manager.editRecord(1, 915, 1815);

        const auto result = manager.findRecordsByEmployeeId(42);

        REQUIRE(result.size() == 2);
        REQUIRE(result[0]->id == 1);
        REQUIRE(result[0]->checkinTime == 915);
        REQUIRE(result[0]->checkoutTime == 1815);
    }

    SECTION("edit missing record throws")
    {
        REQUIRE_THROWS_AS(manager.editRecord(999, 0, 0), std::invalid_argument);
    }

    SECTION("list records")
    {
        const auto all = manager.listRecords();

        REQUIRE(all.size() == 3);
    }
}

TEST_CASE("Test EmployeeService","[EmployeeService]")
{

}