/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE :Write a function template selection Sort. Write a program that inputs, sorts and outputs 
an integer array and a float array. 
*/


#include <iostream>
using namespace std;

template <class T>
class Sort {
    T a[50]; // Array to hold elements
    int n;   // Number of elements

public:
    void insert() {
        cout << "\nHow many elements are there? ";
        cin >> n;
        cout << "\nEnter the numbers:\n";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void selectionSort() {
        T temp;
        int exchange = 0, cmp = 0; // Track exchanges and comparisons

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                cmp++; // Increment comparisons
                if (a[j] < a[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                // Swap elements
                temp = a[i];
                a[i] = a[minIndex];
                a[minIndex] = temp;
                exchange++; // Increment exchanges
            }

            // Display the array after each pass
            cout << "\n\tAfter Pass " << i + 1 << ":\n";
            for (int k = 0; k < n; k++) {
                cout << "\t" << a[k];
            }
            cout << "\n";
        }

        // Display the number of exchanges and comparisons
        cout << "\n\tTotal Number of Exchanges: " << exchange;
        cout << "\n\tTotal Number of Comparisons: " << cmp << "\n";
    }

    void display() const {
        cout << "\nThe sorted list is:\n";
        for (int i = 0; i < n; i++) {
            cout << "\t" << a[i] << endl;
        }
    }
};

int main() {
    cout << "Sorting integers:" << endl;
    Sort<int> intSorter;
    intSorter.insert();
    intSorter.selectionSort();
    intSorter.display();

    cout << "\nSorting floating-point numbers:" << endl;
    Sort<float> floatSorter;
    floatSorter.insert();
    floatSorter.selectionSort();
    floatSorter.display();

    return 0;
}
