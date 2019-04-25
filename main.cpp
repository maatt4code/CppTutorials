/* 
 * File for testing example code
 */

#include "TemplateImplememnationInCpp.h"
#include "NonCopyable.hpp"

int main(int argc, char** argv)
{
    NonCopyable::test();
    TemplateClass<Struct1> t1{Struct1()};
    TemplateClass<Struct2> t2{Struct2()};
    return 0;
}
