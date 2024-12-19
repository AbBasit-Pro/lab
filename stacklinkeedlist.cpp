#include <iostream>
#include <stack>
using namespace std;

// Define the structure for a node
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};

// Stack to hold nodes
 Node* top = nullptr;

// Function to insert a new node at the top of the stack
void push(int n) {
    Node* newNode = new Node();
    newNode->data = n;
    newNode->next = top;  // Initially, the next pointer is null
    top=newNode;
     cout << n <<"The stack pushed" << endl;
}

 

// Function to traverse the linked list (using stack)
void traverse() {
    if (top==nullptr) {
        cout << "The stack is empty." << endl;
        return;
    }     Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

}
 void pop() {
    if (top == nullptr) {
        cout << "The stack is empty. Cannot pop." << endl;
        return;
    }   Node* tempNode = top;
    top = top->next;  // Move the top pointer to the next node
    delete tempNode;  // Delete the old top node
    cout << "Node popped from the stack." << endl;
}
void peek() {
    if (top == nullptr) {
        cout << "The stack is empty." << endl;
        return;
    }
    cout << "Top element is: " << top->data << endl;
}
int main() {
    // Insert elements into the linked list (stack)
    push(10);
    push(20);
    // pop();
    
    // Traverse the stack (linked list)
    cout << "Linked List: ";
    traverse();

    // Search for an element
    

    return 0;
}
