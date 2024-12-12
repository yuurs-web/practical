/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Pizza parlor accepting maximum M orders. Orders are served in first come first served 
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using 
circular queue using array.
*/

#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    int front, rear, size, capacity;
    string* queue;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        front = rear = size = 0;
        queue = new string[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Function to add an order
    void enqueue(string order) {
        if (size == capacity) {
            cout << "Order queue is full. Cannot accept new orders." << endl;
            return;
        }
        queue[rear] = order;
        rear = (rear + 1) % capacity;
        size++;
        cout << "Order added: " << order << endl;
    }

    // Function to serve an order
    void dequeue() {
        if (size == 0) {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Serving order: " << queue[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    // Function to display current orders
    void displayOrders() {
        if (size == 0) {
            cout << "No current orders." << endl;
            return;
        }
        cout << "Current orders in the queue: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    int M;
    cout << "Enter maximum number of orders (M): ";
    cin >> M;

    CircularQueue orderQueue(M);
    int choice;
    string order;

    do {
        cout << "\nMenu:\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display current orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the order: ";
            cin.ignore(); // To clear the newline character from input buffer
            getline(cin, order);
            orderQueue.enqueue(order);
            break;
        case 2:
            orderQueue.dequeue();
            break;
        case 3:
            orderQueue.displayOrders();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
