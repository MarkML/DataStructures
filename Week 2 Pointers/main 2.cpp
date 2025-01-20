/******************************************************************************

vectors as function arguments

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;


int SumOfElements(vector<int>* vecPtr){      //vecPtr is a pointer to a vector
    int sum = 0;
    if(vecPtr == nullptr){                   //check if pointer is valid, dereferencing a nullptr will crash your program
        return -1;
    }
    for (int i = 0; i < vecPtr->size(); i++){
        sum += (*vecPtr)[i];
    }
    return sum;
}
int main()
{
    vector<int> A = {1,2,3,4,5,6,7};   //create a vector of integers
    int total = SumOfElements(&A);     //pass by reference vector A as an argument
    cout << total;

    return 0;
}