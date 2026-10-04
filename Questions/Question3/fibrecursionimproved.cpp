//Memoization
#include <iostream>
using namespace std;

int fib(int n, int dp[]) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    int dp[100];

    for (int i = 0; i < 100; i++)
        dp[i] = -1;

    cout << "Fibonacci number = " << fib(n, dp);

    return 0;
}