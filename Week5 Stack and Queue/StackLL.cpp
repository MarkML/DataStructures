#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* head;

public:
    LinkedListStack() : head(nullptr) {}

    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty!" << endl;
            return -1; // Return a default value or throw an exception
        }

        int poppedData = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return poppedData;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void printStack() {
        Node* current = head;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListStack stack;

    // Push some elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    // Print the stack
    stack.printStack(); // Output: Stack: 20 15 10 5

    // Pop elements from the stack
    cout << "Popped: " << stack.pop() << endl; // Output: Popped: 20
    cout << "Popped: " << stack.pop() << endl; // Output: Popped: 15

    // Print the stack after popping
    stack.printStack(); // Output: Stack: 10 5

    return 0;
}
