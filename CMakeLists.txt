cmake_minimum_required(VERSION 3.16)
project(AttendanceManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成 compile_commands.json，供 CLion / clangd / clang-tidy 使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#引入Catch2和json库
include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.1
        GIT_SHALLOW    TRUE
)
FetchContent_Declare(
        nlohmann_json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
        URL_HASH SHA256=d6c65aca6b1ed68e7a182f4757257b107ae403032760ed6ef121c9d55e81757d
)
FetchContent_MakeAvailable(Catch2 nlohmann_json)

add_library(CLIModule SHARED Src/CLIInterface.cpp Src/CLIParser.cpp Src/CommandActioner.cpp)
target_include_directories(CLIModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_library(EmployeeModule SHARED Src/Employee.cpp Src/EmployeeManager.cpp)
target_include_directories(EmployeeModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_library(AttendanceModule SHARED Src/AttendanceRecord.cpp Src/AttendanceManager.cpp)
target_include_directories(AttendanceModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_library(common SHARED Src/common/TimeStampConvent.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_executable(AttendanceManager Src/main.cpp)
target_link_libraries(AttendanceManager PRIVATE AttendanceModule CLIModule EmployeeModule common nlohmann_json::nlohmann_json)

include(CTest)

if (BUILD_TESTING)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    include(Catch)

    add_executable(tests Test/test.cpp)
    target_link_libraries(tests PRIVATE common CLIModule Catch2::Catch2WithMain)

    catch_discover_tests(tests)
endif ()
