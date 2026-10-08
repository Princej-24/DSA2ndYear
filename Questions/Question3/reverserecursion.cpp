#include <iostream>
using namespace std;

int reverseNumber(int n, int rev = 0) {

    if (n == 0)
        return rev;

    rev = rev * 10 + n % 10;

    return reverseNumber(n / 10, rev);
}

int main() {
    int n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Reverse = " << reverseNumber(n);

    return 0;
}