// remove a specified node from the list
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
        if (curNode == nullptr) { 
            // Special case, remove head
            Node* nodeToRemove = head;
            head = head->next;
            delete nodeToRemove;
            

            if (head == nullptr) { // Remove last item
                tail = nullptr;
            }
        } else if (curNode->next) {
            Node* nodeToRemove = curNode->next;
            Node* succeedingNode = nodeToRemove->next;
            curNode->next = succeedingNode;
            delete nodeToRemove;

            if (succeedingNode == nullptr) { // Removed tail
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

    // Build initial list: 10 20 30 40 50 60
    myList.ListAppend(10);
    myList.ListAppend(20);
    myList.ListAppend(30);
    myList.ListAppend(40);
    myList.ListAppend(50);
    myList.ListAppend(60);
    cout << "Initial ";
    myList.PrintList();

    // 1 Remove HEAD (pass nullptr)
    myList.ListRemoveNodeAfter(nullptr);
    cout << "After removing HEAD (should remove 10): ";
    myList.PrintList();

    // 2 Remove node after HEAD (remove 30)
    myList.ListRemoveNodeAfter(myList.head);
    cout << "After removing node after HEAD (should remove 30): ";
    myList.PrintList();

    // 3 Remove a middle node’s next (remove 50 after 40)
    Node* cur = myList.head;
    while (cur && cur->data != 40) cur = cur->next;
    myList.ListRemoveNodeAfter(cur);
    cout << "After removing node after 40 (should remove 50): ";
    myList.PrintList();

    // 4 Remove the TAIL (remove 60 after 40, updates tail)
    myList.ListRemoveNodeAfter(cur);
    cout << "After removing tail (should remove 60): ";
    myList.PrintList();

    return 0;
}
