#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    stack<char> st;

    cout << "Enter string: ";
    cin >> str;

    // Push characters
    for (char ch : str) {
        st.push(ch);
    }

    // Pop characters
    cout << "Reversed string: ";

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}