/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: In any language program mostly syntax error occurs due to unbalancing delimiter such 
as (),{},[]. Write C++ program using stack to check whether given expression is well 
parenthesized or not. 
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// TITLE: In any language program, mostly syntax error occurs due to unbalancing delimiters such as (), {}, []. Write C++ program using stack to check whether the given expression is well parenthesized or not.

bool isBalanced(const std::string& expression) {
    stack<char> stack;

    // Iterate through each character in the expression
    for (char ch : expression) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // Check for closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty, it's unbalanced
            if (stack.empty()) {
                return false;
            }

            // Check for matching opening bracket
            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty, all brackets were matched
    return stack.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(std::cin, expression);

    // Check if the expression is balanced
    if (isBalanced(expression)) {
        cout << "VALID EXPRESSION" << std::endl;
    } else {
        cout << "INVALID EXPRESSION" << std::endl;
    }

    return 0;
}
