#include <iostream>

using namespace std;

// Node class representing a single element in the doubly linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node

    // Constructor to initialize a new node with given data
    Node(int item) : data(item), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class to manage the list
class DoublyLinkedList {
public:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list

    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Member function to append a new node at the end of the list
    void ListAppend(int item) {
        // Step 1: Create a new node with the given data
        Node* newNode = new Node(item);

        // Step 2: Check if the list is empty
        if (head == nullptr) {  // If the list is empty, set head and tail to the new node
            head = newNode;
            tail = newNode;
        } else {  // If the list is not empty, add the new node to the end
            tail->next = newNode;  // Set the next pointer of current tail to new node
            newNode->prev = tail;  // Set the previous pointer of new node to current tail
            tail = newNode;        // Update tail to the new node
        }
    }

    // Display the list from head to tail
    void PrintForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void PrintReverse() {
    Node* current = tail;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

};

int main() {
    // Step 1: Create an empty doubly linked list
    DoublyLinkedList* myList = new DoublyLinkedList();

    // Step 2: Append values to the list using the member function
    cout << "Appending values: 10, 20, 30 using member function" << endl;
    myList->ListAppend(10);
    myList->ListAppend(20);
    myList->ListAppend(30);
    myList->ListAppend(40);
    

    // Step 3: Display the list to verify the append function works
    cout << "List after Append (Forward): ";
    myList->PrintForward();
    cout << "List printed in Reverse order" << endl;
    myList->PrintReverse();

    return 0;
}
