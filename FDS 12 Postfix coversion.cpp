#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluate(int op1, int op2, char op) {
    switch (op) {
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '+': return op2 + op1;
        case '-': return op2 - op1;
        default: return 0;
    }
}

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (size_t i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert character digit to integer
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            int result = evaluate(op1, op2, ch);
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string postfix = "abc+*d/";
    cout << "Enter values for operands:\n";

    // Replace variables with numeric values
    for (size_t i = 0; i < postfix.length(); i++) {
        if (isalpha(postfix[i])) {
            cout << postfix[i] << " = ";
            char value;
            cin >> value;
            postfix[i] = value; // Replace variable with the digit input
        }
    }

    int result = evaluatePostfix(postfix);
    cout << "\nExpression evaluates to " << result << endl;
    return 0;
}
