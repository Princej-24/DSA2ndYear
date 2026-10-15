//Direct Recursion
#include <iostream>
using namespace std;

void fun(int n) {
    if (n == 0)
        return;

    cout << n << " ";
    fun(n - 1);   // Function calls itself
}

int main() {
    fun(5);
    return 0;
}

// Indirect Recursion 

#include <iostream>
using namespace std;

void fun2(int n);

void fun1(int n) {
    if (n <= 0)
        return;

    cout << n << " ";
    fun2(n - 1);
}

void fun2(int n) {
    if (n <= 0)
        return;

    cout << n << " ";
    fun1(n - 1);
}

int main() {
    fun1(5);
    return 0;
}