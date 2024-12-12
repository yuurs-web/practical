/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Department of Computer Engineering has student's club named 'Pinnacle Club'. Students 
of second, third and final year of department can be granted membership on request. Similarly 
one may cancel the membership of club. First node is reserved for president of club and last 
node is reserved for secretary of club. Write C++ program to maintain club member‘s 
information using singly linked list. Store student PRN and Name. Write functions to: 
a) Add and delete the members as well as president or even secretary. 
b) Compute total number of members of club 
c) Display members 
d) Two linked lists exists for two divisions. Concatenate two lists.
*/

#include<iostream>
#include<cstring>
using namespace std;

struct node {
    int prn;
    char name[20];
    node *next;
};

class Pinnacle {
    node *head = NULL, *tail = NULL;

public:
    // Create a new member (general member)
    void create() {
        int data;
        char name1[20];
        node *temp = new node;

        cout << "Enter the PRN: ";
        cin >> data;
        cout << "Enter the Name: ";
        cin >> name1;

        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Add a new president (first node)
    void president() {
        int data;
        char name1[20];
        node *temp = new node;

        cout << "Enter the PRN of President: ";
        cin >> data;
        cout << "Enter the Name of President: ";
        cin >> name1;

        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = head;
        head = temp;
    }

    // Add a new member
    void member() {
        int data;
        char name1[20];
        node *temp = new node;

        cout << "Enter the PRN of Member: ";
        cin >> data;
        cout << "Enter the Name of Member: ";
        cin >> name1;

        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Display all members
    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->prn << " ---> " << temp->name << "\n";
            temp = temp->next;
        }
    }

    // Compute total number of members
    void total() {
        int count = 0;
        node *current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        cout << "Total number of members: " << count << endl;
    }

    // Delete the president
    void Delete_pre() {
        if (head != NULL) {
            node *temp = head;
            head = head->next;
            delete temp;
            cout << "President has been removed.\n";
        } else {
            cout << "The list is empty.\n";
        }
    }

    // Delete the secretary (last member)
    void Delete_sec() {
        if (head != NULL) {
            node *current = head;
            node *prev = NULL;

            while (current->next != NULL) {
                prev = current;
                current = current->next;
            }

            if (prev != NULL) {
                prev->next = NULL;
                delete current;
                cout << "Secretary has been removed.\n";
            } else {
                delete head;
                head = NULL;
                cout << "The list is empty.\n";
            }
        } else {
            cout << "The list is empty.\n";
        }
    }

    // Delete a member by PRN
    void Delete_mem() {
        int prn;
        cout << "Enter the PRN of the member to delete: ";
        cin >> prn;

        node *current = head;
        node *prev = NULL;

        while (current != NULL && current->prn != prn) {
            prev = current;
            current = current->next;
        }

        if (current != NULL) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next; // Deleting the head node
            }
            delete current;
            cout << "Member with PRN " << prn << " has been removed.\n";
        } else {
            cout << "Member not found.\n";
        }
    }

    // Concatenate two linked lists
    void concatenate(Pinnacle &other) {
        if (this->head == NULL) {
            this->head = other.head;
            this->tail = other.tail;
        } else if (other.head != NULL) {
            this->tail->next = other.head;
            this->tail = other.tail;
        }
        other.head = other.tail = NULL; // Clear the second list
    }
};

int main() {
    Pinnacle p1, p2;
    int ch1, ch2, ch3;
    char cont;

    do {
        cout << "\tMENU\n";
        cout << "\t1. Create\n";
        cout << "\t2. Display\n";
        cout << "\t3. Insert Member\n";
        cout << "\t4. Total Members\n";
        cout << "\t5. Delete\n";
        cout << "***************************************\n";
        cout << "\tEnter your choice: ";
        cin >> ch1;

        switch (ch1) {
        case 1:
            p1.create();
            break;

        case 2:
            p1.display();
            break;

        case 3:
            cout << "\t1. President\n";
            cout << "\t2. Member\n";
            cout << "Enter your choice: ";
            cin >> ch2;

            switch (ch2) {
            case 1:
                p1.president();
                break;
            case 2:
                p1.member();
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }
            break;

        case 4:
            p1.total();
            break;

        case 5:
            cout << "\t1. President\n";
            cout << "\t2. Member\n";
            cout << "\t3. Secretary\n";
            cout << "Enter your choice: ";
            cin >> ch3;

            switch (ch3) {
            case 1:
                p1.Delete_pre();
                break;
            case 2:
                p1.Delete_mem();
                break;
            case 3:
                p1.Delete_sec();
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }
            break;

        default:
            cout << "Invalid choice.\n";
            break;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
