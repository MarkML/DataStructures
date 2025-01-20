//double pointers part 2 

#include <iostream>
using namespace std;

int main(){
    int num = 10;
    int* ptr1 = &num;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;
    
    cout << "address of num is: " << &num << endl;
    cout << "value of num is: " << num << endl;
    cout << "value of ptr1 is: " << ptr1 << endl;
    cout << "value of ptr2 is: " << ptr2 << endl;
    
    cout << "value of *ptr1 is " << *ptr1 << endl;
    cout << "value of *ptr2 is " << *ptr2 << endl;
    cout << "value of **ptr2 is " << **ptr2 << endl;
    
    cout << "value of ptr3 is: " << ptr3 << endl;
    cout << "value of *ptr3 is: " << *ptr3 << endl;
    cout << "value of **ptr3 is: " << **ptr3 << " " << *(*ptr3) << endl;
    cout << "value of ***ptr3 is: " << ***ptr3 << " " << *(*(*ptr3)) << endl;
}