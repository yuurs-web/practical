/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE : Write a program in C++ to use map associative container. The keys will be the 
names of states and the values will be the populations of the states. When the program 
runs, the user is prompted to type the name of a state. The program then looks in the 
map, using the state name as an index and returns the population of the state. 
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Define the map with string keys (state names) and integer values (population)
    typedef map<string, int> mType;
    mType popMap;

    // Insert state population data into the map
    popMap.insert(pair<string, int>("Maharashtra", 7026357));
    popMap.insert(pair<string, int>("Rajasthan", 6578936));
    popMap.insert(pair<string, int>("Karnataka", 6678993));
    popMap.insert(pair<string, int>("Punjab", 5789032));
    popMap.insert(pair<string, int>("West Bengal", 6676291));

    // Display the size of the map
    cout << "\tPopulation of states in India\n";
    cout << "\nSize of popMap: " << popMap.size() << "\n";

    // Prompt user to enter a state name
    string state;
    cout << "\nEnter name of the state: ";
    cin >> state;

    // Find the state in the map
    mType::iterator it = popMap.find(state);

    // Check if the state exists in the map and display the population
    if (it != popMap.end())
        cout << state << "'s population is " << it->second << "\n";
    else
        cout << "State not found in popMap\n";

    // Clear the map
    popMap.clear();
    cout << "Map cleared. Size of popMap: " << popMap.size() << "\n";

    return 0;
}
