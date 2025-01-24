#include<iostream>
using namespace std;
/*

Class templates allow you to define a class that work with different data types

template<typename T>
class ClassName {
    T data; // generic data types
public: 
    ClassName(T value) : data(value) {}
    T getValue() {
        return data;
    }
}

*/

template<typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);          // Box instance of type int
    Box<double> doubleBox(3.14);  // Box instance of type double

    cout << intBox.getValue() << endl;
    cout << doubleBox.getValue() << endl;
    
    return 0;
}