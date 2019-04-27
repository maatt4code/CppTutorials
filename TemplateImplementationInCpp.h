/**
 * @file TemplateImplementationInCpp
 *
 * @brief This and the associated *.cpp file demonstrates how to write
 * template implementation in *cpp file rather than *.h
 *
 * @author M
 *
 */

#pragma once

#include <string>

// Some dummy structs that we instantiate our template class with
struct Struct1
{
    const std::string wisdom{"Options increase happiness"};
};

struct Struct2
{
    const std::string wisdom{"Too many options decrease happiness"};
};

// Template class we use for this example
template<class T>
class TemplateClass
{
public:
    TemplateClass(const T&);
    ~TemplateClass();
    void doStuff();
};
