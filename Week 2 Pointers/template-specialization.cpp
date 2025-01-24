/******************************************************************************
Template specialization
Assign different behavior for a specific type.
sometimes a partiular type such as 'string' requires a behavior that
deviates from generic behavior defined by the template

template<>
class Classname<SpecificType> {
    // specialized implementation for SpecificType
}
*******************************************************************************/
#include <iostream>
using namespace std;

template<typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    T getValue(){
        return value;
    }
};
// describe specialized behaviro for string type
template<>
class Box<string> {
    string value;
public:
    Box(string val) : value("String: " + val) {}
    string getValue() {
        return value;
    }
};

int main()
{
    Box<int> intBox(10);
    Box<string> stringBox("Hello");
    
    cout << intBox.getValue() << endl;
    cout << stringBox.getValue() << endl;
    return 0;
}