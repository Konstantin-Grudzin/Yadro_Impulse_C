#pragma once
#include <iostream>
#include <compare>

class Time
{
private:
    int value;
    Time(int value):value(value){};
public:
    Time(const std::string& s);
    ~Time() = default;
    auto operator<=>(const Time&) const = default;
    int operator-(const Time& other) 
    {
        return value - other.value;
    }
    Time& operator+=(int other)
    {
        value+=other;
        return *this;
    }
    int getValue() {return value;}
    std::string str() const;
};

