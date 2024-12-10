/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE : Imagine a publishing company which does marketing for book and audio cassette 
versions. Create a class publication that stores the title (a string) and price (type float) of a 
publication. From this class derive two classes: book, which adds a page count (type int), and 
tape, which adds a playing time in minutes (type float). Write a program that instantiates the 
book and tape classes, allows user to enter data and displays the data members. If an exception 
is caught, replace all the data member values with zero values. 
*/

#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;

public:
    virtual void getdata() {
        cout << "\nEnter the title: ";
        cin >> ws; // To handle leading whitespaces
        getline(cin, title);
        cout << "Enter the price: ";
        cin >> price;
    }

    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~publication() {} // Virtual destructor for proper cleanup
};

class book : public publication {
private:
    int page_count;

public:
    void getdata() override {
        publication::getdata();
        cout << "Enter the number of pages: ";
        cin >> page_count;
    }

    void display() const override {
        publication::display();
        cout << "Page Count: " << page_count << endl;
    }
};

class tape : public publication {
private:
    float playtime;

public:
    void getdata() override {
        publication::getdata();
        cout << "Enter the playing time in minutes: ";
        cin >> playtime;
    }

    void display() const override {
        publication::display();
        cout << "Playing Time: " << playtime << " minutes" << endl;
    }
};

int main() {
    publication *ptr; // Base class pointer
    book b;
    tape t;

    // Book details
    ptr = &b;
    cout << "\nEnter details for Book:";
    ptr->getdata();
    cout << "\nBook Details:";
    ptr->display();

    // Tape details
    ptr = &t;
    cout << "\nEnter details for Tape:";
    ptr->getdata();
    cout << "\nTape Details:";
    ptr->display();

    return 0;
}
