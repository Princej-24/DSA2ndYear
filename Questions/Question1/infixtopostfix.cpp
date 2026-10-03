#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main() {
    string infix, postfix = "";
    stack<char> st;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (char ch : infix) {

        // Operand
        if (isalnum(ch)) {
            postfix += ch;
        }

        // Opening bracket
        else if (ch == '(') {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }

        // Operator
        else {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Empty remaining stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}