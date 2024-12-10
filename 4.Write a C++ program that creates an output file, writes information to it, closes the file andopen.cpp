/*
Name : Prem Gopal Chuniyan
Roll No : 75
Title:Write a C++ program that creates an output file, writes information to it, closes the file andopen 
it again as an input file and read the information from the file. 
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Sample {
public:
    int roll_num;
    char name[20];

    // Method to input values
    void getvalue() {
        cout << "\nEnter the roll number: ";
        cin >> roll_num;
        cin.ignore(); // To handle leftover newline character
        cout << "Enter the name: ";
        cin.getline(name, 20);
    }

    // Method to display values
    void show() const {
        cout << "\nRoll Number: " << roll_num << "\nName: " << name << endl;
    }
};

int main() {
    Sample obj;

    // File paths
    const char* file_path = "test.txt";

    // Writing to file
    ofstream os(file_path, ios::binary);
    if (!os) {
        cerr << "Could not open output file for writing.\n";
        exit(1);
    }
    cout << "\nEnter details for the student:";
    obj.getvalue();
    cout << "Writing the contents to the file...\n";
    os.write(reinterpret_cast<char*>(&obj), sizeof(obj));
    if (!os) {
        cerr << "Could not write to file.\n";
        exit(1);
    }
    os.close();

    // Reading from file
    ifstream is(file_path, ios::binary);
    if (!is) {
        cerr << "Could not open input file for reading.\n";
        exit(1);
    }
    cout << "Reading the contents from the file...\n";
    is.read(reinterpret_cast<char*>(&obj), sizeof(obj));
    if (!is) {
        cerr << "Could not read from file.\n";
        exit(1);
    }
    obj.show();
    is.close();

    return 0;
}
