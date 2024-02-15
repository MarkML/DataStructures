#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
   int data;
   Node* next;
   Node* previous;

   //constructor
   Node(int initialData) {
      data = initialData;
      next = nullptr;
      previous = nullptr;
   }
};

class LinkedList {
private:
   Node* head;
   Node* tail;

public:
    //constructor
   LinkedList() {
      head = nullptr;
      tail = nullptr;
   }
   
   // destructor, It deallocates memory occupied by the linked list nodes. It iterates through the list, deleting each node.
   ~LinkedList() {
      Node* currentNode = head;
      while (currentNode) {
         Node* toBeDeleted = currentNode;
         currentNode = currentNode->next;
         delete toBeDeleted;
      }
   }
   
   string PrintList() {
      Node* currentNode = head;
      string listAsString = "";

      while (currentNode != nullptr) {
         listAsString += to_string(currentNode->data);

         currentNode = currentNode->next;

         // Add a space after each node, except the last one
         if (currentNode != nullptr) {
               listAsString += ", ";
         }
      }
      return listAsString;
   }

   string PrintListBackwards() {
      Node* currentNode = tail;
      string listAsString = "";

      while (currentNode != nullptr) {
         // If the list string is not empty, prepend a space
         if (!listAsString.empty()) {
            listAsString = listAsString + ", ";
         }

         // Prepend the current node's data to the string
         listAsString = listAsString + to_string(currentNode->data);

         currentNode = currentNode->previous;
      }

      return listAsString;
   }
    
   void Append(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         newNode->previous = tail;
         tail = newNode;
      }
   }
   
   void Prepend(Node* newNode) {
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else {
         newNode->next = head;
         head->previous = newNode;
         head = newNode;
      }
   }

   void InsertAfter(Node* currentNode, Node* newNode) {
      // loop through the list till we find the node OR reach the nullptr
      if(currentNode != nullptr) {
         Node* node = head;
         while (node != nullptr && node != currentNode) {
            node = node->next;
         }
      
         if (node == nullptr) {
            // The node is not in the list, exit the function
            return;
         }
      }
      
      if (head == nullptr) {
         head = newNode;
         tail = newNode;
      }
      else if (currentNode == tail) {
         tail->next = newNode;
         newNode->previous = tail;
         tail = newNode;
      }
      else {
         Node* successor = currentNode->next;
         newNode->next = successor;
         newNode->previous = currentNode;
         currentNode->next = newNode;
         successor->previous = newNode;
      }
   }
   
   void Remove(Node* currentNode) {
      //ensure the node to be removed is in the list before proceeding to remove it
      if(currentNode != nullptr) {
         Node* node = head;
         while (node != nullptr && node != currentNode) {
            node = node->next;
         }
      
         if (node == nullptr) {
            // The node is not in the list, exit the function
            return;
         }
      }
      
      Node* successor = currentNode->next;
      Node* predecessor = currentNode->previous;
      
      if (successor) {
         successor->previous = predecessor;
      }
      if (predecessor) {
         predecessor->next = successor;
      }
         
      if (currentNode == head) {
         head = successor;
      }
      if (currentNode == tail) {
         tail = predecessor;
      }
      
      delete currentNode;
   }
};

#endif