/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE : Crete User defined exception to check the following conditions and throw the exception 
if the criterion does not meet. 
a) User has age between 18 and 55 
b) User stays have income between Rs. 50,000 – Rs. 1,00,000 per month 
c) User stays in Pune/ Mumbai/ Bangalore / Chennai 
d) User has 4-wheeler Accept age, Income, City, Vehicle from the user and check for the 
conditions mentioned above. If any of the condition not met then throw the exception 
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int age;
    int vehicleType;
    double income;
    char city[20];

    // Input and validation for age
    cout << "\nEnter the age of the person: ";
    cin >> age;
    try {
        if (age < 18 || age > 55) {
            throw age;
        }
        cout << "\nValid age: " << age;
    } catch (int) {
        cout << "\nError: Age must be between 18 and 55.";
        return 1; // Exit the program if the age is invalid
    }

    // Input and validation for income
    cout << "\nEnter the income of the person: ";
    cin >> income;
    try {
        if (income < 50000 || income > 100000) {
            throw income;
        }
        cout << "\nValid income: " << income;
    } catch (double) {
        cout << "\nError: Income should be in the range of 50000 to 100000.";
        return 1; // Exit the program if the income is invalid
    }

    // Input and validation for city
    cout << "\nEnter the city of residence: ";
    cin >> city;
    try {
        if (strcmp(city, "Pune") != 0 && strcmp(city, "Mumbai") != 0 &&
            strcmp(city, "Bangalore") != 0 && strcmp(city, "Chennai") != 0) {
            throw city;
        }
        cout << "\nValid city: " << city;
    } catch (const char[]) {
        cout << "\nError: City must be Pune, Mumbai, Bangalore, or Chennai.";
        return 1; // Exit the program if the city is invalid
    }

    // Input and validation for vehicle type
    cout << "\nEnter type of vehicle (2 for two-wheeler, 4 for four-wheeler): ";
    cin >> vehicleType;
    try {
        if (vehicleType != 2 && vehicleType != 4) {
            throw vehicleType;
        }
        cout << "\nValid vehicle type: " << vehicleType << " wheeler";
    } catch (int) {
        cout << "\nError: Vehicle type must be either 2 or 4 wheeler.";
        return 1; // Exit the program if the vehicle type is invalid
    }

    return 0;
}
