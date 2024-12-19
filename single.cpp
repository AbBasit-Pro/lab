#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};
Node* head = nullptr; // Global head pointer for the linked list

// Function to insert a new node at the beginning of the linked list
void insert(int n) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = n;          // Assign the data
    newNode->next = head;       // Link the new node to the current head
    head = newNode;             // Update the head
}
void deleteLast() {
    if (head == nullptr) {      // If the list is empty
        cout << "The list is empty. Cannot delete." << endl;
        return;
    }

    if (head->next == nullptr) { // If the list has only one node
        delete head;             // Delete the single node
        head = nullptr;          // Set head to nullptr
        cout << "Last node deleted. List is now empty." << endl;
        return;
    }

    // Traverse to the second-to-last node
    Node* temp = head;
    while (temp->next->next != nullptr) { // Stop at the second-to-last node
        temp = temp->next;
    }

    delete temp->next;          // Delete the last node
    temp->next = nullptr;       // Update the second-to-last node's next pointer
    cout << "Last node deleted." << endl;
}
void deleteNode( ) {
    if (head == nullptr) {      // If the list is empty
        cout << "The list is empty. Cannot delete." << endl;
    
    }

    
     
        Node* temp = head;      // Store the current head
        head = head->next;      // Move the head to the next node
        delete temp;            // Delete the old head
      
        
    }
void insertAtPosition(int position, int n) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = n;          // Assign the data

    if (position == 1) {        // If inserting at the head
        newNode->next = head;   // Point new node to current head
        head = newNode;         // Update the head
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next; // Traverse to the node before the desired position
    }

    if (temp == nullptr) {      // If the position is out of bounds
        cout << "Position out of bounds." << endl;
         
    }

    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode;       // Link previous node to the new node
}

// Function to insert a new node at the end of the linked list
void insertEnd(int n) {
    Node* newNode = new Node(); // Create a new node
    newNode->data = n;          // Assign the data
    newNode->next = nullptr;    // Set the next pointer to null

    if (head == nullptr) {      // If the list is empty
        head = newNode;         // Set the new node as the head
        return;
    }

    Node* temp = head;          // Start traversing from the head
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;       // Link the last node to the new node
}

// Function to traverse and print the elements of the linked list
void traverse() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    
}
 bool searchElement(int key) {
    Node* temp = head;          // Start traversing from the head
    int position = 1;           // Keep track of the position
    while (temp != nullptr) {   // Traverse the list
        if (temp->data == key) { // If the element is found
            cout << "Element " << key << " found at position " << position << "." << endl;
            return true;
        }
        temp = temp->next;      // Move to the next node
        position++;
    }
    cout << "Element " << key << " not found in the list." << endl;
    return false;
}
int main() {
    // Insert elements into the linked list
    insertEnd(55);
    insert(10);
    insert(20);
    insert(30);  
    insert(40);

    // Insert an element at a specific position
    insertAtPosition(3, 25);

    // Traverse and display the linked list
    traverse();
//   deleteLast(); traverse(); 
searchElement(20);
    return 0;
}


#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};

// LinkedList class to manage the list
class LinkedList {
private:
    Node* head;     // Head pointer for the linked list

public:
    // Constructor to initialize the head
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning
    void insert(int n) {
        Node* newNode = new Node();
        newNode->data = n;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the end
    void insertEnd(int n) {
        Node* newNode = new Node();
        newNode->data = n;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int position, int n) {
        Node* newNode = new Node();
        newNode->data = n;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete the last node
    void deleteLast() {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Last node deleted. List is now empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        cout << "Last node deleted." << endl;
    }

    // Function to delete the first node
    void deleteFirst() {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node deleted." << endl;
    }

    // Function to search for an element
    bool searchElement(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << "." << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }

        cout << "Element " << key << " not found in the list." << endl;
        return false;
    }

    // Function to traverse and print the linked list
    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Insert elements into the list
    list.insertEnd(55);
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Insert an element at a specific position
    list.insertAtPosition(3, 25);

    // Display the linked list
    cout << "Linked List: ";
    list.traverse();

    // Search for an element
    list.searchElement(20);

    // Delete the last node
    list.deleteLast();
    cout << "After deleting last node: ";
    list.traverse();

    // Delete the first node
    list.deleteFirst();
    cout << "After deleting first node: ";
    list.traverse();

    return 0;
}
