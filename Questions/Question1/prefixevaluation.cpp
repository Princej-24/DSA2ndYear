#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
    string exp;
    stack<int> st;

    cout << "Enter prefix expression: ";
    cin >> exp;

    reverse(exp.begin(), exp.end());

    for (char ch : exp) {

        if (isdigit(ch)) {
            st.push(ch - '0');
        }

        else {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            switch (ch) {
                case '+':
                    st.push(a + b);
                    break;

                case '-':
                    st.push(a - b);
                    break;

                case '*':
                    st.push(a * b);
                    break;

                case '/':
                    st.push(a / b);
                    break;
            }
        }
    }

    cout << "Result = " << st.top();

    return 0;
}