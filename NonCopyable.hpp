// This class demonstrates how to use piecewise_construct and forward_as_tuple
// to new add elments into containers without copying 

#include <string>
#include <iostream>

using namespace std;

class NonCopyable
{
private:
    int value = 0;
    std::string str;

public:
    NonCopyable(int v, const std::string& s) : value(v), str(s) {}

    // ensure this class is non-copyable
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&& o) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    // function for easy debugging
    friend std::ostream& operator<<(std::ostream& os, const NonCopyable& o) {
        os << "[" << o.value << "] (" << o.str << ")"; 
        return os;
    }

    // demo code for adding non-copyable objects to a container
    static void test() {
        std::map<int, NonCopyable> m;

        // This line will break compilation
        //m.emplace(1, NonCopyable(1, "Hello"));

        // Use piecewise_construct and forward_as_tuple
        // to avoid copying
        m.emplace(std::piecewise_construct,
              std::forward_as_tuple(1),
              std::forward_as_tuple(1, "hello"));
        m.emplace(std::piecewise_construct,
              std::forward_as_tuple(2),
              std::forward_as_tuple(2, "good bye"));
 
        // Debug Print
        for(const auto& i : m)
            std::cout << i.second << std::endl;
    }
};
