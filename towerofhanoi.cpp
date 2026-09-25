#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source
             << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary); // first recursive call 

    // Move the largest disk from source to destination
    cout << "Move disk " << n << " from " << source
         << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}