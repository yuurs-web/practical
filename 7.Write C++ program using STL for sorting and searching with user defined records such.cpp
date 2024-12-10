/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE ; Write C++ program using STL for sorting and searching with user defined records such 
as person record(Name, DOB, Telephone number), Item record (Item code, name, cost,quantity) 
using vector container. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Product {
public:
    char productName[20];
    int quantity;
    int price;
    int id;

    // Overloading equality operator for comparison
    bool operator==(const Product& p) {
        return id == p.id;
    }

    // Overloading less-than operator for sorting
    bool operator<(const Product& p) {
        return id < p.id;
    }
};

// Inventory as a global vector
vector<Product> inventory;

// Function declarations
void insert();
void display();
void search();
void remove();
void sortByPrice();
void print(Product& p);

// Comparator function for sorting by price
bool compareByPrice(const Product& p1, const Product& p2) {
    return p1.price < p2.price;
}

// Main function
int main() {
    int choice;
    do {
        cout << "\n***** Menu *****";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort by Price";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: sortByPrice(); break;
            case 5: remove(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice. Please try again.";
        }
    } while (choice != 6);

    return 0;
}

// Function to insert a product
void insert() {
    Product p;
    cout << "\nEnter Product Name: ";
    cin >> p.productName;
    cout << "Enter Quantity: ";
    cin >> p.quantity;
    cout << "Enter Price: ";
    cin >> p.price;
    cout << "Enter Product ID: ";
    cin >> p.id;
    inventory.push_back(p);
    cout << "\nProduct added successfully.";
}

// Function to display all products
void display() {
    if (inventory.empty()) {
        cout << "\nInventory is empty.";
        return;
    }
    for_each(inventory.begin(), inventory.end(), print);
}

// Helper function to print a product
void print(Product& p) {
    cout << "\nProduct Name: " << p.productName;
    cout << "\nQuantity: " << p.quantity;
    cout << "\nPrice: " << p.price;
    cout << "\nProduct ID: " << p.id;
    cout << "\n-----------------------";
}

// Function to search for a product
void search() {
    Product p;
    cout << "\nEnter Product ID to search: ";
    cin >> p.id;
    auto it = find(inventory.begin(), inventory.end(), p);
    if (it == inventory.end()) {
        cout << "\nProduct not found.";
    } else {
        cout << "\nProduct found:";
        print(*it);
    }
}

// Function to remove a product
void remove() {
    Product p;
    cout << "\nEnter Product ID to delete: ";
    cin >> p.id;
    auto it = find(inventory.begin(), inventory.end(), p);
    if (it == inventory.end()) {
        cout << "\nProduct not found.";
    } else {
        inventory.erase(it);
        cout << "\nProduct deleted successfully.";
    }
}

// Function to sort inventory by price
void sortByPrice() {
    if (inventory.empty()) {
        cout << "\nInventory is empty.";
        return;
    }
    sort(inventory.begin(), inventory.end(), compareByPrice);
    cout << "\nInventory sorted by price.";
    display();
}
