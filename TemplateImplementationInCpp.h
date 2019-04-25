#pragma once

#include <string>

struct Struct1
{
    const std::string wisdom{"Options increase happiness"};
};

struct Struct2
{
    const std::string wisdom{"Too many options decrease happiness"};
};

template<class T>
class TemplateClass
{
public:
    TemplateClass(const T&);
    ~TemplateClass();
    void doStuff();
};
