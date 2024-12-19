void bubbleSort() {
    if (head == nullptr || head->next == nullptr) {
        // If the list is empty or contains only one element, no sorting is required
        return;
    }

    // Calculate the length of the linked list
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // Perform bubble sort using a for loop
    for (int i = 0; i < length - 1; i++) {
        Node* current = head;
        Node* prev = nullptr;

        for (int j = 0; j < length - i - 1; j++) {
            if (current->data > current->next->data) {
                // Swap the data of adjacent nodes
                swap(current->data, current->next->data);
            }
            current = current->next; // Move to the next node
        }
    }
}



void reverseDisplay() {
    node* temp = head;  // Start from the head of the list
    if (temp == NULL)   // Check if the list is empty
        return;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward and print the data
    while (temp != NULL) {
        cout << temp->info << "\t";
        temp = temp->prev;
    }
    cout << endl;
}    
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { // Queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        Node* temp = front;
        int data = temp->data;
        front = front->next;

        if (front == nullptr) { // Queue becomes empty
            rear = nullptr;
        }

        delete temp; // Free memory of dequeued node
        return data;
    }

    // Get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to clean up the allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function to demonstrate the queue
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue elements: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Queue elements after dequeue: ";
    q.display();

    return 0;
}
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // To avoid overflow

        // Check if target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller, ignore the right half
        else if (arr[mid] > target)
            high = mid - 1;

        // If target is larger, ignore the left half
        else
            low = mid + 1;
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 10, 15, 18, 20, 30, 50, 100};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = binarySearch(arr, size, target);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
