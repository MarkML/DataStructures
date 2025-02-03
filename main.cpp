#include "DoublyLinkedList.h"
#include "ListAppend.h"
#include "ListPrepend.h"
#include "ListSearch.h"
#include "ListInsertNodeAfter.h"
#include "ListRemoveNode.h"

using namespace std;

int main() {
    DoublyLinkedList myList;

    // Append elements
    ListAppend(&myList, 10);
    ListAppend(&myList, 20);
    ListAppend(&myList, 30);

    cout << "List after Append (Forward): ";
    myList.displayForward();

    cout << "List after Append (Backward): ";
    myList.displayBackward();

    // Prepend elements
    ListPrepend(&myList, 5);
    ListPrepend(&myList, 1);

    cout << "List after Prepend (Forward): ";
    myList.displayForward();

    cout << "List after Prepend (Backward): ";
    myList.displayBackward();

    // Search for a node and insert after it
    int searchValue = 10;
    Node* foundNode = ListSearch(&myList, searchValue);
    if (foundNode) {
        cout << "Inserting 15 after " << searchValue << endl;
        Node* newNode = new Node(15);
        ListInsertNodeAfter(&myList, foundNode, newNode);
    }

    cout << "List after Insert (Forward): ";
    myList.displayForward();

    cout << "List after Insert (Backward): ";
    myList.displayBackward();

    // Remove a node
    int removeValue = 20;
    Node* nodeToRemove = ListSearch(&myList, removeValue);
    if (nodeToRemove) {
        cout << "Removing " << removeValue << endl;
        ListRemoveNode(&myList, nodeToRemove);
    }

    cout << "List after Remove (Forward): ";
    myList.displayForward();

    cout << "List after Remove (Backward): ";
    myList.displayBackward();

    return 0;
}
