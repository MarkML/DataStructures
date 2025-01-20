/*
Pointer-to-Pointer can be useful for 
1. modifying original pointers.  i.e. change the address stored in a pointer
2. dybnamic memory amangement i.e. managing an array of pointers or multi-dimensional arrays.
3. complex data structures: linked liss, tree, graphs, i.e. nodes with pointers
4. function parameters
*/



#include <iostream>
using namespace std;

void swap(int** a, int** b){
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main(){
    
    int num1 = 20;
    int num2 = 40;
    //create pointers
    int* ptr1 = &num1;
    int* ptr2 = &num2;
    //swap using pointer to pointer
    
    cout << "Befores swap: num1 = " << *ptr1 << " num2 = " << *ptr2 << endl;
    swap(&ptr1, &ptr2); //&ptr1 is type int**
    //after swap
    cout << "After swap: num1 = " << num1 << " num2 = " << num2 << endl;
}

/*

void swap(int** a, int** b) { // a and b are pointer to a pointer.  var a receives an address
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int num1 = 20, num2 = 40;
    int* ptr1 = &num1;
    int* ptr2 = &num2;

    cout << "Before swap: num1 = " << *ptr1 << ", num2 = " << *ptr2 << endl;
    swap(&ptr1, &ptr2);  // pass address of pointers
    cout << "After swap: num1 = " << *ptr1 << ", num2 = " << *ptr2 << endl;

    return 0;
}
*/
