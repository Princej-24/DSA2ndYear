//Tail
#include <iostream>
using namespace std;

void fun(int n) {
    if (n == 0)
        return;

    cout << n << " ";

    fun(n - 1);   // Last operation
}

int main() {
    fun(5);
    return 0;
}

// Non Tail
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    cout << factorial(5);
    return 0;
}