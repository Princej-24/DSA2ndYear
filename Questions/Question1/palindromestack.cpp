#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num, original, digit;

    stack<int> st;

    cout << "Enter number: ";
    cin >> num;

    original = num;

    // Store digits in stack
    while (num > 0) {
        digit = num % 10;
        st.push(digit);
        num = num / 10;
    }

    num = original;

    bool palindrome = true;

    // Compare digits
    while (num > 0) {
        digit = num % 10;

        if (digit != st.top()) {
            palindrome = false;
            break;
        }

        st.pop();
        num = num / 10;
    }

    if (palindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}