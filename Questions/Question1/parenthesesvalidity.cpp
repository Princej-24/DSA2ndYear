#include <iostream>
#include <stack>
using namespace std;

bool isValid(string exp) {
    stack<char> s;

    for (char ch : exp) {
        if (ch == '(')
            s.push(ch);

        else if (ch == ')') {
            if (s.empty())
                return false;

            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    if (isValid(exp))
        cout << "Expression is Valid";
    else
        cout << "Expression is Invalid";

    return 0;
}