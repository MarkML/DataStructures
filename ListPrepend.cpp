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

    // Member function to prepend a new node at the beginning of the list
    void ListPrepend(int item) {
        // Step 1: Create a new node with the given data
        Node* newNode = new Node(item);

        // Step 2: Check if the list is empty
        if (!head) {  // If the list is empty, set head and tail to the new node
            head = newNode;
            tail = newNode;
        } else {  // If the list is not empty, insert the new node at the beginning
            newNode->next = head;  // Set new node's next to current head
            head->prev = newNode;  // Set current head's previous to new node
            head = newNode;        // Update head to the new node
        }
    }

    // Display the list from head to tail
    void displayForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Step 1: Create an empty doubly linked list
    DoublyLinkedList myList;

    // Step 2: Prepend values to the list using the member function
    cout << "Prepending values: 30, 20, 10 using member function" << endl;
    myList.ListPrepend(30);
    myList.ListPrepend(20);
    myList.ListPrepend(10);

    // Step 3: Display the list to verify the prepend function works
    cout << "List after Prepend (Forward): ";
    myList.displayForward();

    return 0;
}
