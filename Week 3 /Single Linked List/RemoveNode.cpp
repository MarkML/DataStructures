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

    // Function to remove the node after a given node in the list
    void ListRemoveNodeAfter(Node* curNode) {
        if (curNode == nullptr && head != nullptr) { // Special case, remove head
            Node* sucNode = head->next;
            delete head;
            head = sucNode;

            if (sucNode == nullptr) { // Removed last item
                tail = nullptr;
            }
        } else if (curNode->next != nullptr) {
            Node* sucNode = curNode->next->next;
            delete curNode->next;
            curNode->next = sucNode;

            if (sucNode == nullptr) { // Removed tail
                tail = curNode;
            }
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

    // Print the list
    myList.PrintList();
    
    // Remove some items after printing the list
    if (myList.head != nullptr) {
        // Remove the second item (20)
        myList.ListRemoveNodeAfter(myList.head);
    }

    // Print the updated list
    myList.PrintList();

    return 0;
}
