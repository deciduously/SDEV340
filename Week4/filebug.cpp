/*
* SDEV340 Week 4 discussion
* demonstrative example demonstrating issues with pass-by-value on objects, as small as possible
* Benjamin Lovy
*/

#include <iostream>

class CoolObject
{
    int coolValue;

public:
    CoolObject()
    {
        coolValue = 5;
    }
    int getCoolValue() const
    {
        return coolValue;
    }
    void setCoolValue(int val)
    {
        coolValue = val;
    }
};

void setCoolValueToTen(CoolObject co)
{
    using std::cout;
    cout << "Current: " << co.getCoolValue() << " | Setting...\n";
    co.setCoolValue(10);
    cout << "New: " << co.getCoolValue() << "\n";
}

void reallySetCoolValueToTen(CoolObject &co)
{
    using std::cout;
    cout << "Current: " << co.getCoolValue() << " | Setting...\n";
    co.setCoolValue(10);
    cout << "New: " << co.getCoolValue() << "\n";
}

int main()
{
    using std::cout;
    CoolObject co1;
    CoolObject co2;
    cout << "co1: " << co1.getCoolValue() << " | co2: " << co2.getCoolValue() << "\n";
    setCoolValueToTen(co2);
    cout << "co1: " << co1.getCoolValue() << " | co2: " << co2.getCoolValue() << "\n";
    reallySetCoolValueToTen(co2);
    cout << "co1: " << co1.getCoolValue() << " | co2: " << co2.getCoolValue() << "\n";
    return 0;
}