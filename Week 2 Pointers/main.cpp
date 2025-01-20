/******************************************************************************

Intro to Stack and Heap
operators:  new and delete

*******************************************************************************/
#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

int main() {
    int* num1 = new int(11); // a memory allocation of size int is made on the Heap 
    int* num2 = num1;
    
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    
    cout << "num1 = " << *num1 << endl;
    cout << "num2 = " << *num2 << endl;
    
   
    delete num1;   // Deallocate the dynamically allocated memory on the Heap
    
    num1 = nullptr;   //after delete, the pointers still point to the freed memory location
    num2 = nullptr;   //always set pointers to nullptr after de-allocating to avoid "dangling pointer" problem
    return 0;         //pointers get deleted when they fall out of scope
}


