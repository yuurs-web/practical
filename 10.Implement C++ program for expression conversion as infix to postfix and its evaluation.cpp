/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Implement C++ program for expression conversion as infix to postfix and its evaluation 
using stack based on given conditions: 1. Operands and operator, both must be single character. 
2. Input Postfix expression must be in a desired format. 3. Only '+', '-', '*' and '/ ' operators are 
expected.
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // For isdigit() function
using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> opStack;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {  // If the character is an operand
            postfix += ch;
        } else if (ch == '(') {
            opStack.push(ch);
        } else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();  // Remove the '(' from stack
        } else {  // The character is an operator
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch);
        }
    }
    
    // Pop all the operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }
    
    return postfix;
}

// Function to evaluate the postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> valueStack;

    for (char ch : postfix) {
        if (isdigit(ch)) {  // If the character is a digit
            valueStack.push(ch - '0');  // Convert char to int
        } else {  // The character is an operator
            int right = valueStack.top();
            valueStack.pop();
            int left = valueStack.top();
            valueStack.pop();

            switch (ch) {
                case '+': valueStack.push(left + right); break;
                case '-': valueStack.push(left - right); break;
                case '*': valueStack.push(left * right); break;
                case '/': 
                    if (right != 0) 
                        valueStack.push(left / right); 
                    else {
                        cout << "Error: Division by zero" << endl;
                        return 0;
                    }
                    break;
                default: 
                    cout << "Error: Invalid operator" << endl;
                    return 0;
            }
        }
    }
    
    return valueStack.top();  // The result is the last item on the stack
}

int main() {
    string infix;
    
    cout << "Enter an infix expression (e.g., A+B*C): ";
    cin >> infix;
    
    // Convert infix to postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate the postfix expression (only single digit operands)
    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;
    
    return 0;
}
