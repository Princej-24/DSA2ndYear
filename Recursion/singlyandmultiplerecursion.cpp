//Single Recursion
#include <iostream>
using namespace std;

void fun(int n) {
    if (n == 0)
        return;

    cout << n << " ";

    fun(n - 1);   // Only ONE recursive call
}

int main() {
    fun(5);
    return 0;
}

//Multiple Recursion
#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);  // TWO recursive calls
}

int main() {
    cout << fib(5);
    return 0;
}