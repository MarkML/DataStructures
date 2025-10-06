#include <iostream>
#include <vector>

using namespace std; 

class Stack {
private:
    vector<int> elements; // Use a vector to store elements

public:
    // Constructor: Initialize an empty stack
    Stack() {
        // The vector is automatically initialized when it's constructed.
        // No additional setup is required here.
    }

    // Push operation: Adds an item to the top of the stack
    void push(int item) {
        elements.push_back(item); // Add the item to the end of the vector
    }

    // Pop operation: Removes the item at the top of the stack
    void pop() {
        if (!isEmpty()) {
            elements.pop_back(); // Remove the last element from the vector
        } else {
            cout << "Stack is empty! Cannot pop." << endl;
        }
    }

    // Top operation: Returns the item at the top of the stack without removing it
    int peek() {
        if (!isEmpty()) {
            return elements.back(); // Return the last element of the vector
        }
        cout << "Stack is empty! Cannot get top element." << endl;
        return -1;
    }

    // isEmpty operation: Checks if the stack is empty
    bool isEmpty() {
        return elements.empty(); // Check if the vector is empty
    }
    
    int GetLength() {
        if (!isEmpty()) {
            return elements.size();
        }
        return 0;
    }
};

int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    //Get length of queue
    cout << "The number of items in the stack: " << stack.GetLength() << endl;
    // Print the top element of the stack
    cout << "Top element of the stack: " << stack.peek() << endl;

    // Pop elements from the stack and print them
    cout << "Popping elements from the stack:" << endl;
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    cout << endl;

    // Check if the stack is empty after each operation and print the result
    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

