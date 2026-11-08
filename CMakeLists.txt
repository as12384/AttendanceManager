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


add_library(common SHARED Lib/common/TimeStampConvent.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_library(entity SHARED Lib/Employee.cpp Lib/AttendanceRecord.cpp)
target_include_directories(entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)

add_library(JsonStorage SHARED Lib/JsonStorage.cpp)
target_include_directories(JsonStorage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)
target_link_libraries(JsonStorage nlohmann_json::nlohmann_json)

add_library(manager SHARED Lib/EmployeeManager.cpp Lib/AttendanceManager.cpp)
target_include_directories(manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)
target_link_libraries(manager entity)

add_library(services SHARED Lib/EmployeeService.cpp)
target_include_directories(services PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc )
target_link_libraries(services JsonStorage manager)

add_library(CLIModule SHARED Lib/CLIInterface.cpp Lib/CLIParser.cpp Lib/CommandActioner.cpp)
target_include_directories(CLIModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Inc)
target_link_libraries(CLIModule services common)


add_executable(AttendanceManager Src/main.cpp)
target_link_libraries(AttendanceManager PRIVATE CLIModule)

include(CTest)

if (BUILD_TESTING)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    include(Catch)

    add_executable(tests Test/test.cpp)
    target_link_libraries(tests PRIVATE common CLIModule Catch2::Catch2WithMain)

    catch_discover_tests(tests)
endif ()

