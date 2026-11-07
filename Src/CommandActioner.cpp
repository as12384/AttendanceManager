#include <string>
#include <vector>

namespace CMD
{
    void Test(std::vector<std::string> args)
    {
        throw(std::runtime_error("gugugaga!!!!!"));
    }
}