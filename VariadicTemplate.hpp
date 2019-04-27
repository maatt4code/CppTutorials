/**
 * @file VariadicTemplate.hpp
 *
 * @brief Demonstration of how to construct variadic template function.
 * this example simply takes a stringstream and your arguements and just
 * append all your arguements to it
 *
 * @author M
 *
 */

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

    
// let's do 2 at a time to make it more complicated
template<typename T1, typename T2, typename... Args>
void append(std::stringstream& ss, const T1& first, const T2& second, Args... args)
{
    std::cout << __PRETTY_FUNCTION__ << "\n";
    ss << first << ", " << second << ", ";
    // pass the remaining arguments down the chain.
    // This function may be called recursively or
    // one of the above terminal functions may be called
    // depending on the number of arguments remaining.
    append(ss, args...);
};
}
