//
// Created by lucas on 2026/11/6.
//
#include "common/TimeStampConvent.h"

#include <chrono>
#include <sstream>
#include <stdexcept>
#include <string>

long TimetoStamp(
        const std::string& timestr,
        const std::string& format)
{
    using namespace std::chrono;

    std::istringstream ss(timestr);
    system_clock::time_point tp;

    ss >> parse(format, tp);

    if (std::string rest; !ss || ss >> rest) {
        throw std::invalid_argument("Format Parsing Failed");
    }

    return duration_cast<seconds>(tp.time_since_epoch()).count();
}
