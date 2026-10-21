#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    // Pop
    st.pop();
    cout << "After pop, top element: " << st.top() << endl;

    // Push another element
    st.push(40);

    cout << "Top element: " << st.top() << endl;

    // Display stack
    cout << "Stack elements: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}