/* 
 * File for testing example code 
 */

#include "TemplateImplememnationInCpp.h"
#include "NonCopyable.hpp"
#include "VariadicTemplate.hpp"

int main(int argc, char** argv)
{
    NonCopyable::test();
    
    TemplateClass<Struct1> t1{Struct1()};
    TemplateClass<Struct2> t2{Struct2()};
    
    {
        // odd number of inputs
        std::stringstream ss;
        VariadicTemplate::append(ss, 1, "two", 'c', false, 5.5);
        std::cout << ss.str() << std::endl;
    }
    {
        // even numbers of inputs
        std::stringstream ss;
        VariadicTemplate::append(ss, 1, "two", 'c', false);
        std::cout << ss.str() << std::endl;
    }
    {
        // no inputs - Well, this case is just invalid
        //std::stringstream ss;
        //VariadicTemplate::append(ss);
        //std::cout << ss.str() << std::endl;
    }
    return 0;
}
