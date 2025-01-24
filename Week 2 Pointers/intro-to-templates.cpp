/******************************************************************************

Function templates allow you to write a single function that works with any data type.

*******************************************************************************/
#include <iostream>
using namespace std;

// step 1. Define a function template
template <typename T>
T add(T a, T b) {  //'T' is a placeholder for a data type
    return a + b;  // generic function for any type T where '+' operation is valid
}

int main() {
    //ex1. compiler deduces that T is int because both arguments are ints
    int intResult = add(5,10);
    cout << "Integer addition: " << intResult << endl;

    //ex2. compiler is explicitly told T is int, useful for mixed types
    int mixedResult = add<int>(5,10.5);
    cout << "Integer plus Float: " << mixedResult << endl;
    
    //ex3. use template with floating point data typename
    double doubleResult = add<double>(5.5, 2.3);
    cout << "Double addition: " << doubleResult << endl;
    
    //ex4.use template with strings
    string stringResult = add<string>("Hello,", "World!");
    cout << "String concatenation: " << stringResult << endl;
    
    return 0;
}
