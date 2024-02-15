#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
   LinkedList numList;
   Node* nodeA = new Node(14);
   Node* nodeB = new Node(2);
   Node* nodeC = new Node(20);
   Node* nodeD = new Node(31);
   Node* nodeE = new Node(16);
   Node* nodeF = new Node(55);

   numList.Append(nodeA);   // Add 14
   numList.Append(nodeB);   // Add 2, make the tail
   numList.Append(nodeC);   // Add 20, make the tail

   numList.Prepend(nodeD);  // Add 31, make the head

   numList.InsertAfter(nodeB, nodeE);  // Insert 16 after 2
   numList.InsertAfter(nodeC, nodeF);  // Insert 55 after tail, 55 becomes new tail

   // Output list
   cout << "List after adding nodes: " << numList.PrintList() << endl;
   cout << "List after adding nodes (backwards): " << numList.PrintListBackwards() << endl;

   // Remove the tail node, then the head node
   numList.Remove(nodeF);
   numList.Remove(nodeD);

   // Output final list
   cout << "List after removing nodes: " << numList.PrintList() << endl;
   cout << "List after removing nodes (backwards): " << numList.PrintListBackwards() << endl;
}