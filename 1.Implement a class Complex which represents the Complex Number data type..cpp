/*
cd 
TITLE : Implement a class Complex which represents the Complex Number data type. 
Implement the following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overloaded operator+ to add two complex numbers. 
3. Overloaded operator* to multiply two complex numbers. 
4. Overloaded << and >> to print and read Complex Numbers. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

class complex {
public:
    float real_num, img_num;

    // Default constructor
    complex() : real_num(0), img_num(0) {}

    // Operator overloading for addition
    complex operator+(complex obj) {
        complex temp;
        temp.real_num = real_num + obj.real_num;
        temp.img_num = img_num + obj.img_num;
        return temp;
    }

    // Operator overloading for multiplication
    complex operator*(complex obj) {
        complex temp;
        temp.real_num = real_num * obj.real_num - img_num * obj.img_num;
        temp.img_num = img_num * obj.real_num + real_num * obj.img_num;
        return temp;
    }

    // Friend function for input
    friend istream &operator>>(istream &is, complex &obj) {
        cout << "Enter real part: ";
        is >> obj.real_num;
        cout << "Enter imaginary part: ";
        is >> obj.img_num;
        return is;
    }

    // Friend function for output
    friend ostream &operator<<(ostream &out, const complex &obj) {
        out << obj.real_num;
        if (obj.img_num >= 0)
            out << "+"; // To display a '+' for positive imaginary part
        out << obj.img_num << "i";
        return out;
    }
};

int main() {
    complex a, b, c, d;
    int ch;

    cout << "\nThe first complex number is:";
    cin >> a;

    cout << "\nThe second complex number is:";
    cin >> b;

    do {
        cout << "\nEnter Your Choice:\n1. Addition\n2. Multiplication\n3. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            c = a + b;
            cout << "\nAddition = " << c << endl;
            break;

        case 2:
            d = a * b;
            cout << "\nMultiplication = " << d << endl;
            break;

        case 3:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (ch != 3);

    return 0;
}
