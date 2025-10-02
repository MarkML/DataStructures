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

    // Member function to insert a new node after a specific node
    void ListInsertNodeAfter(Node* currentNode, Node* newNode) {
        
        if (head == nullptr) {              //empty list    
           head = newNode;
           tail = newNode;
        }
        else if (currentNode == tail) {    //inserting after tail
           tail->next = newNode;
           newNode->prev = tail;
           tail = newNode;
        }
        else {
           Node* successor = currentNode->next;   //inserting after middle node
           newNode->next = successor;
           newNode->prev = currentNode;
           currentNode->next = newNode;
           successor->prev = newNode;
        }
    }

    // Member function to append a new node at the end of the list (for testing purposes)
    void ListAppend(int item) {
        Node* newNode = new Node(item);

        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Member function to search for a node with a specific value (for finding insertion point)
    Node* ListSearch(int dataValue) {
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == dataValue) {
                return currentNode;  // Return the node if found
            }
            currentNode = currentNode->next;
        }
        return nullptr;
    }

    // Display the list from head to tail
    void PrintForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList* myList = new DoublyLinkedList();

    // 1. Create sample data
    cout << "Appending values: 10, 20, 30, 40, 50\n";
    myList->ListAppend(10);
    myList->ListAppend(20);
    myList->ListAppend(30);
    myList->ListAppend(40);
    myList->ListAppend(50);

    cout << "Initial list: ";
    myList->PrintForward();     // 10 20 30 40 50

    // 2. Insert in the middle: insert 35 after 30
    Node* node30 = myList->ListSearch(30);
    if (node30 != nullptr) {
        Node* node35 = new Node(35);
        myList->ListInsertNodeAfter(node30, node35);
        cout << "After inserting 35 after 30: ";
        myList->PrintForward(); // 10 20 30 35 40 50
    }

    // 3. Insert after the tail: insert 60 after 50
    Node* node50 = myList->ListSearch(50);
    if (node50 != nullptr) {
        Node* node60 = new Node(60);
        myList->ListInsertNodeAfter(node50, node60);
        cout << "After inserting 60 after 50 (tail): ";
        myList->PrintForward(); // 10 20 30 35 40 50 60
    }

    // 4. Insert after the head: insert 15 after 10
    Node* node10 = myList->ListSearch(10);
    if (node10 != nullptr) {
        Node* node15 = new Node(15);
        myList->ListInsertNodeAfter(node10, node15);
        cout << "After inserting 15 after 10: ";
        myList->PrintForward(); // 10 15 20 30 35 40 50 60
    }

    // 5. Insert into an empty list
    DoublyLinkedList* emptyList = new DoublyLinkedList();
    Node* node100 = new Node(100);
    emptyList->ListInsertNodeAfter(nullptr, node100); // inserting into empty list
    cout << "Insert into empty list (should be 100): ";
    emptyList->PrintForward();  // 100

    return 0;
}
