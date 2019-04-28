
/**
 * @file NonPODUnion.hpp
 *
 * @brief Example of how to implement a Union of non-Plain-Old-Data.
 * The following will avoid using implicitly deleted constrictor / destructor
 *
 * @author M
 *
 */
#pragma once

#include <string>
#include <vector>
#include <mutex>

struct DummyMember
{
    int i = 911;
    // why not make this more complex than it needs to :-)
    std::mutex mx;
};

struct NonPODUnion
{
public:
    // 1) enum specifying what type it is, so we know what to create and destroy
    enum class Type : int32_t {
        None = 0,
        String = 1,
        Vector = 2,
        Struct = 3
    };
private:
    // 2) outside world DOES need to know about type info - but not direct access.
    // you can make this non-const of you need copy-ctor etc
    const Type type = Type::None;

public:
    // 3) Declare your union - keep it anonymous to make things simple
    union {
        std::string str;
        std::vector<int> vec;
        DummyMember dum;
    };

    // 4) do NOT have an "instance" of the above union:
    // - anonymous means the declaration *is* your instance that you act directly on, so do NOT do "union {...} data;"
    // - making it non-anonymous means you will have an instance, so then you will have to have default ctor / dtor
    // - if you have to have ctor / dtor, then you cannot use "type" information :-@

    NonPODUnion(const Type& t) : type(t)
    {
        // 5.a) give data type, explicitly call correct constructor (placement new)
        switch(type) {
            case Type::String:
                new (&str) std::string("Moo");
                break;
            case Type::Vector:
                new (&vec) std::vector<int>{5,7,4};
                break;
            case Type::Struct:
                new (&dum) DummyMember();
                break;
            default:
                throw std::runtime_error("Unexpected Data Type");
        }
    }
    ~NonPODUnion() {
        // 5.b) give data type, explicitly call correct destructor
        switch(type) {
            case Type::String:
                str.~basic_string();
                break;
            case Type::Vector:
                vec.~vector();
                break;
            case Type::Struct:
                dum.~DummyMember();
                break;
            default:
                break;
        }
    }

    // 6) Accessor for type info so outside world knows how to handle this data
    const Type& getType() const {return type;}

    // for this example, make it non-copyable etc for now
    NonPODUnion(const NonPODUnion&) = delete;
    NonPODUnion(NonPODUnion&&) = delete;
    NonPODUnion& operator=(const NonPODUnion&) = delete;
    
};
