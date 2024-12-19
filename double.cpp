#include <iostream>
using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {
    int data;       // Data part of the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node
};
Node* head = nullptr;
 
// Function to insert a new node at the beginning of the list
void insertAtBeginning(int n) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = n;          // Assign data
    newNode->prev = nullptr;    // The new node has no previous node
    newNode->next = head;       // The new node points to the  

    if (head != nullptr) {      // If the list is not empty
        head->prev = newNode;   // Update the previous pointer of the current head
   
}   head = newNode; 
                // Update the head to the new node
}

// Function to insert a new node at the end of the list
 void traverse() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl; // Indicate the end of the list
}
void insertAtEnd(int n) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = n;          // Assign data
    newNode->next = nullptr;    // The new node has no next node
    newNode->prev = nullptr;    // The new node has no previous node initially

    if (head == nullptr) {      // If the list is empty
        head = newNode;         // Set the new node as the head
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;   // Link the last node to the new node
        newNode->prev = temp;   // Link the new node to the previous last node
    }
}

int main() {
    // Insert elements into the doubly linked list
    insertAtBeginning(10);
    insertAtBeginning(20); insertAtEnd(444);
    traverse();

    return 0;
}
