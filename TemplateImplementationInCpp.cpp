/**
 * @file TemplateImplementationInCpp.cpp
 *
 * @brief This and the associated *.h file demonstrates how to write
 * template implementation in *.cpp file rather than *.h
 *
 * @author M
 *
 */

#include "TemplateImplememnationInCpp.h"
#include <iostream>

// Constructor prints out the wisdom of the concrete class
template<class T>
TemplateClass<T>::TemplateClass(const T& t) {
    // SFINAE
    std::cout << t.wisdom << std::endl;
}

template<class T>
TemplateClass<T>::~TemplateClass() {
}

// Declare these here so implementation can be seen during compilation
template TemplateClass<Struct1>::TemplateClass(const Struct1&);
template TemplateClass<Struct1>::~TemplateClass();
template TemplateClass<Struct2>::TemplateClass(const Struct2&);
template TemplateClass<Struct2>::~TemplateClass();

// No need to declare void doStuff here as it is never used
