// Insert a node after a specific node in the list
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
    
    // Search for a value
    Node* ListSearch(int key) {
        Node* curNode = head;
        while (curNode != nullptr) {
            if (curNode->data == key) {
                return curNode;        // found
            }   
            curNode = curNode->next;
        }
        return nullptr;                // not found
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
        https://www.onlinegdb.com/classroom    cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }
};

int main() {
    List myList;
    myList.ListAppend(10);
    myList.ListAppend(20);
    myList.ListAppend(30);
    myList.ListAppend(40);

    myList.PrintList();

    Node* newNode = new Node(25);

    // use the new search method
    Node* curNode = myList.ListSearch(20);

    // insert after 20 if it exists and has a next node
    if (curNode && curNode->next) {
        myList.ListInsertAfter(curNode, newNode);
    }

    myList.PrintList();
    return 0;
}
