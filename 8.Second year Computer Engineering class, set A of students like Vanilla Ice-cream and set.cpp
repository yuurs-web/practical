/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set 
B of students like butterscotch ice-cream. Write C++ program to store two sets using linked list. 
compute and display- a) Set of students who like both vanilla and butterscotch b) Set of students 
who like either vanilla or butterscotch or not both c) Number of students who like neither 
vanilla nor butterscotch.
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// TITLE: Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like Butterscotch Ice-cream. 
// Write a C++ program to store two sets using linked list. Compute and display:
// a) Set of students who like both vanilla and butterscotch.
// b) Set of students who like either vanilla or butterscotch or not both.
// c) Number of students who like neither vanilla nor butterscotch.

struct Node {
    string name;
    Node* next;
};

// Function to insert a student into the linked list
void insert(Node*& head, const string& name) {
    Node* newNode = new Node{name, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(Node* head) {
    while (head) {
        cout << head->name << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to compute the intersection of two sets
unordered_set<string> intersection(Node* listA, Node* listB) {
    unordered_set<string> setA;
    unordered_set<string> result;

    // Store names from listA
    while (listA) {
        setA.insert(listA->name);
        listA = listA->next;
    }

    // Find intersection with listB
    while (listB) {
        if (setA.find(listB->name) != setA.end()) {
            result.insert(listB->name);
        }
        listB = listB->next;
    }
    return result;
}

// Function to compute the union of two sets
unordered_set<string> unionSets(Node* listA, Node* listB) {
    unordered_set<string> result;

    // Add names from listA
    while (listA) {
        result.insert(listA->name);
        listA = listA->next;
    }

    // Add names from listB
    while (listB) {
        result.insert(listB->name);
        listB = listB->next;
    }
    return result;
}

int main() {
    Node* vanillaStudents = nullptr;
    Node* butterscotchStudents = nullptr;
    int totalStudents;

    // Input total number of students
    cout << "Enter total number of students: ";
    cin >> totalStudents;
    cin.ignore(); // To ignore the newline character after the integer input

    // Input names of all students
    cout << "Enter names of all students (separated by newlines):\n";
    for (int i = 0; i < totalStudents; ++i) {
        string name;
        getline(cin, name);
    }

    // Specify students who like vanilla
    int n;
    cout << "Enter number of students who like vanilla ice-cream: ";
    cin >> n;
    cin.ignore(); // Ignore newline after integer input
    cout << "Enter names of students who like vanilla ice-cream:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        insert(vanillaStudents, name);
    }

    // Specify students who like butterscotch
    cout << "Enter number of students who like butterscotch ice-cream: ";
    cin >> n;
    cin.ignore(); // Ignore newline after integer input
    cout << "Enter names of students who like butterscotch ice-cream:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        insert(butterscotchStudents, name);
    }

    // Compute intersection (students who like both vanilla and butterscotch)
    unordered_set<string> both = intersection(vanillaStudents, butterscotchStudents);
    cout << "Students who like both vanilla and butterscotch: ";
    for (const auto& name : both) {
        cout << name << " ";
    }
    cout << endl;

    // Compute union (students who like either vanilla or butterscotch or both)
    unordered_set<string> either = unionSets(vanillaStudents, butterscotchStudents);
    cout << "Students who like either vanilla or butterscotch (or both): ";
    for (const auto& name : either) {
        cout << name << " ";
    }
    cout << endl;

    // Calculate and display number of students who like neither
    int neither = totalStudents - either.size();
    cout << "Number of students who like neither vanilla nor butterscotch: " << neither << endl;

    // Free linked list memory
    while (vanillaStudents) {
        Node* temp = vanillaStudents;
        vanillaStudents = vanillaStudents->next;
        delete temp;
    }

    while (butterscotchStudents) {
        Node* temp = butterscotchStudents;
        butterscotchStudents = butterscotchStudents->next;
        delete temp;
    }

    return 0;
}
