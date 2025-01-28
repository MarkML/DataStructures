#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// List class definition
class List {
public:
    Node* head;
    Node* tail;

    // Constructor
    List() : head(nullptr), tail(nullptr) {}

    // Function to append a node to the end of the list
    void ListAppend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // Check if the list is empty
            head = newNode; // If empty, set both head and tail to the new node
            tail = newNode;
        } else {
            tail->next = newNode; // If not empty, append the new node after the current tail
            tail = newNode; // Update the tail pointer to the new node
        }
    }


    // Function to insert a node after a given node in the list
    void ListInsertAfter(Node* curNode, Node* newNode) {
        if (head == nullptr) { // List empty
            head = newNode;
            tail = newNode;
        } else if (curNode == tail) { // Insert after tail
            tail->next = newNode;
            tail = newNode;
        } else {
            newNode->next = curNode->next;
            curNode->next = newNode;
        }
    }

    // Function to print the elements of the list
    void PrintList() {
        Node* curNode = head;
        cout << "List: ";
        while (curNode != nullptr) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a list
    List myList;

    // Append some elements to the list
    myList.ListAppend(10);
    myList.ListAppend(20);
    myList.ListAppend(30);
    myList.ListAppend(40);

    // Print the original list
    myList.PrintList();

    // Create a new node to insert
    Node* newNode = new Node(25);

    // Search for the node with value 20
    Node* curNode = myList.head;
    while (curNode != nullptr && curNode->data != 20) {
        curNode = curNode->next;
    }

    // If the node with value 20 is found and it has a next node
    if (curNode != nullptr && curNode->next != nullptr) {
        myList.ListInsertAfter(curNode, newNode);
    }

    // Print the updated list
    myList.PrintList();

    return 0;
}
