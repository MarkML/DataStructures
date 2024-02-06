/******************************************************************************
BubbleSort
*******************************************************************************/
#include <iostream>

using namespace std;

void bubbleSort(int array[] ,int size) {
    for (int i = size-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
          if (array[j] > array[j+1]) {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
           }
        }
    }
}

int main()
{
    
    int array[] = {5,4,5,8,0,67,99,10};
    int size = sizeof(array) / sizeof(array[0]);
    bubbleSort(array,size);
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
