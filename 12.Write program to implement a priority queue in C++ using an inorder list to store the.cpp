/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Write program to implement a priority queue in C++ using an inorder list to store the 
items in the queue. Create a class that includes the data items (which should be template) and 
the priority (which should be int). The inorder list should contain these objects, with operator 
<= overloaded so that the items with highest priority appear at the beginning of the list 
(which will make it relatively easy to retrieve the highest item.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Item {
public:
    T data;
    int priority;

    Item(T data, int priority) : data(data), priority(priority) {}

    // Overloading the <= operator to compare priorities
    bool operator<=(const Item<T>& other) const {
        return this->priority <= other.priority;
    }
};

template <typename T>
class PriorityQueue {
private:
    std::vector<Item<T>> items;

public:
    // Function to insert an item into the priority queue
    void enqueue(T data, int priority) {
        Item<T> newItem(data, priority);
        items.push_back(newItem);
        // Sort the items based on priority in descending order
        std::sort(items.begin(), items.end(), [](const Item<T>& a, const Item<T>& b) {
            return b <= a; // Higher priority first
        });
    }

    // Function to remove and return the highest priority item
    T dequeue() {
        if (items.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        T highestPriorityItem = items.front().data;
        items.erase(items.begin()); // Remove the item with the highest priority
        return highestPriorityItem;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return items.empty();
    }

    // Function to get the highest priority item without removing it
    T peek() const {
        if (items.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        return items.front().data;
    }

    // Function to display the items in the priority queue
    void display() const {
        std::cout << "Priority Queue:\n";
        for (const auto& item : items) {
            std::cout << "Data: " << item.data << ", Priority: " << item.priority << "\n";
        }
    }
};

int main() {
    PriorityQueue<std::string> pq;
    pq.enqueue("Task 1", 2);
    pq.enqueue("Task 2", 5);
    pq.enqueue("Task 3", 1);
    pq.enqueue("Task 4", 3);

    pq.display();

    std::cout << "\nDequeueing highest priority item: " << pq.dequeue() << "\n";
    pq.display();

    std::cout << "\nPeek at highest priority item: " << pq.peek() << "\n";

    return 0;
}
