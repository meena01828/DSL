#include <iostream>
#include <stack> // Using STL stack
#include <string> // For std::string
using namespace std;

bool isValidExpression(const string exp) {
    stack<char> s;
    
    // Iterate using a traditional for-loop (C++98 compatible)
    for (size_t i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false; // Unmatched closing parenthesis
            char top = s.top();
            if ((ch == ')' && top == '(') || 
                (ch == ']' && top == '[') || 
                (ch == '}' && top == '{')) {
                s.pop();
            } else {
                return false; // Mismatched parentheses
            }
        }
    }
    
    return s.empty(); // If stack is empty, expression is valid
}

int main() {
    string exp;
    cout << "\n\t!! Parenthesis Checker !!" << endl;
    cout << "Enter the expression to check: ";
    cin >> exp; // Input string without spaces
    
    if (!exp.empty() && (exp[0] == ')' || exp[0] == ']' || exp[0] == '}')) {
        cout << "\nInvalid Expression..." << endl;
    } else {
        if (isValidExpression(exp)) {
            cout << "\nExpression is well parenthesized." << endl;
        } else {
            cout << "\nInvalid Expression or not well parenthesized." << endl;
        }
    }
    
    return 0;
}
