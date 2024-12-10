/*
Name : Prem Gopal Chuniyan
Roll No : 75

TITLE : Develop an object oriented program in C++ to create a database of student information 
system containing the following information: Name, Roll number, Class, division, Date of Birth, 
Blood group, Contact address, telephone number, driving license no. and other. Construct the 
database with suitable member functions for initializing and destroying the data viz constructor, 
default constructor, Copy constructor, destructor, static member functions, friend class, this 
pointer, inline code and dynamic memory allocation operators-new and delete. 
*/ 


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob; // Date of Birth
    string bloodGroup;
    string address;
    long long telephone;
    string licenseNo;
    static int studentCount;

public:
    // Default constructor
    Student() : rollNumber(0), division('A'), telephone(0) {
        name = "Unknown";
        dob = "00/00/0000";
        studentClass = "Unknown";
        bloodGroup = "Unknown";
        address = "Unknown";
        licenseNo = "Unknown";
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int rollNumber, string studentClass, char division,
            string dob, string bloodGroup, string address, long long telephone,
            string licenseNo)
        : name(name), rollNumber(rollNumber), studentClass(studentClass), division(division),
          dob(dob), bloodGroup(bloodGroup), address(address), telephone(telephone),
          licenseNo(licenseNo) {
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Friend class declaration
    friend class StudentHelper;

    // Inline function to display details
    inline void display() const {
        cout << "\nStudent Details:"
             << "\nName: " << name
             << "\nRoll Number: " << rollNumber
             << "\nClass: " << studentClass
             << "\nDivision: " << division
             << "\nDate of Birth: " << dob
             << "\nBlood Group: " << bloodGroup
             << "\nAddress: " << address
             << "\nTelephone: " << telephone
             << "\nDriving License No.: " << licenseNo << endl;
    }

    // Function to set data using 'this' pointer
    void setData(string name, int rollNumber, string studentClass, char division,
                 string dob, string bloodGroup, string address, long long telephone,
                 string licenseNo) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->address = address;
        this->telephone = telephone;
        this->licenseNo = licenseNo;
    }

    // Dynamic memory allocation and data entry
    static Student* createStudent() {
        string name, studentClass, dob, bloodGroup, address, licenseNo;
        int rollNumber;
        long long telephone;
        char division;

        // Taking input from user
        cout << "Enter Student Name: ";
        getline(cin >> ws, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Class: ";
        getline(cin >> ws, studentClass);
        cout << "Enter Division (A/B/C/...): ";
        cin >> division;
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin >> ws, dob);
        cout << "Enter Blood Group: ";
        getline(cin >> ws, bloodGroup);
        cout << "Enter Address: ";
        getline(cin >> ws, address);
        cout << "Enter Telephone Number: ";
        cin >> telephone;
        cout << "Enter Driving License Number: ";
        getline(cin >> ws, licenseNo);

        // Using new to dynamically create a student object
        return new Student(name, rollNumber, studentClass, division, dob, bloodGroup, address,
                           telephone, licenseNo);
    }

    // Function to delete dynamically allocated student object
    static void deleteStudent(Student* student) {
        delete student;
    }
};

// Initialize static member
int Student::studentCount = 0;

// Friend class definition
class StudentHelper {
public:
    static void showStudentInfo(const Student& student) {
        cout << "Accessing private data from friend class:\n";
        cout << "Name: " << student.name << "\nRoll Number: " << student.rollNumber << endl;
    }
};

int main() {
    int numStudents;
    cout << "Enter the number of students you want to add: ";
    cin >> numStudents;

    // Creating a vector to store pointers to Student objects
    vector<Student*> students;

    // Taking inputs for each student and storing in vector
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for student " << (i + 1) << ":\n";
        students.push_back(Student::createStudent());
    }

    // Display all students' details
    cout << "\n--- Student Information ---";
    for (int i = 0; i < numStudents; ++i) {
        students[i]->display();
    }

    // Displaying total student count
    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

    // Deleting all dynamically allocated student objects
    for (int i = 0; i < numStudents; ++i) {
        Student::deleteStudent(students[i]);
    }

    return 0;
}
