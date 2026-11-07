#include <iostream>
#include <stdexcept>

#include <catch2/catch_test_macros.hpp>

#include "CLIParser.h"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_exception.hpp"
#include "../Src/common/TimeStampConvent.cpp"

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

