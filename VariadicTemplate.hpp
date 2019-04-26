#pragma once

#include <sstream>

namespace VariadicTemplate
{
// terminal condition with one arg remaining
template<typename T>
void append(std::stringstream& ss, const T& t)
{
    // the end. no need to append comma
    std::cout << __PRETTY_FUNCTION__ << "\n";
    ss << t;
};

// terminal condition with two args remaining
template<typename T1, typename T2>
void append(std::stringstream& ss, const T1& first, const T2& second)
{
    // the end. no need to append comma
    std::cout << __PRETTY_FUNCTION__ << "\n";
    ss << first << ", " << second;
};

template<typename T1, typename T2, typename... Args>
void append(std::stringstream& ss, const T1& first, const T2& second, Args... args)
{
    // let's do 2 at a time to make it more complicated
    std::cout << __PRETTY_FUNCTION__ << "\n";
    ss << first << ", " << second << ", ";
    append(ss, args...);
};
}
