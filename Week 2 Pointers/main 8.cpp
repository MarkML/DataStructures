/******************************************************************************
pass by reference using pointers as function arguments

*******************************************************************************/
#include <iostream>

using namespace std;

void Increment(int *a) {
    *a = *a + 1;   //dereference a to get its value and then add 1 and store it
}

int main()
{
    int a = 10;
    cout << "before function call a is: " << a << endl;
    Increment(&a);
    cout << "after function call a is: " << a << endl;
    Increment(&a);
    cout << "after 2nd function call a is: " << a << endl;
 
    return 0;
}