#include <iostream>
#include <stack>
#include <string>
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

bool isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '^';
}

string infixToPostfix(string expression) {
    stack<char> st;
    string result = "";

    for (char ch : expression) {

        if (ch == ' ') {
            continue;
        }

        if (isalnum(ch)) {
            result += ch;
        }

        else if (ch == '(') {
            st.push(ch);
        }

        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }

            if (!st.empty()) {
                st.pop();
            }
        }

        else if (isOperator(ch)) {

            while (ch != '^' &&
                   !st.empty() &&
                   st.top() != '(' &&
                   precedence(st.top()) >= precedence(ch)) {

                result += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    cout << "Postfix expression: "
         << infixToPostfix(expression);

    return 0;
}