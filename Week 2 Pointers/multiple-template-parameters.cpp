/******************************************************************************
Multiple Template Parameters
Define templates with multiple parameters for more flexibility

template<typename T1, typename T2>
class ClassName {
    T1 data1;
    T2 data2;
public:
    ClassName(T1 value, T2 value2) : data1(value1), data2(value2) {}
    void display() {
        cout << data1 << " and " << data2 << endl;
    }
}
*******************************************************************************/
#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void display() {
        cout << first << ", " << second << endl;
    }
};

int main()
{
    Pair<int, double> myPair(10, 3.14);
    myPair.display();
    
    Pair<string, char> anotherPair("Hello", '#');
    anotherPair.display();
   
    return 0;
}