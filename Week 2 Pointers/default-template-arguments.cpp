/******************************************************************************

Default Template Arguments
Templates can have default arguments, providing fallback type
if none is specified

*******************************************************************************/
#include <iostream>
using namespace std;

template<typename T = int>
class Box {
    T value;
public: 
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main()
{
    Box<> defaultBox(5.2);  // uses int as default type
    cout << defaultBox.getValue() << endl;
    
    Box<double> anotherBox(3.14);
    cout << anotherBox.getValue() << endl;
    
    return 0;
}