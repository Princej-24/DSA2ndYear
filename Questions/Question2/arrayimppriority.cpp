//Ascending
#include <iostream>
using namespace std;

#define SIZE 5

class PriorityQueue {
    int arr[SIZE];
    int n;

public:
    PriorityQueue() {
        n = 0;
    }

    void enqueue(int value) {
        if (n == SIZE) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[n++] = value;
    }

    void dequeue() {
        if (n == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        int index = 0;

        // Find smallest element
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[index])
                index = i;
        }

        cout << arr[index] << " deleted\n";

        for (int i = index; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;
    }

    void display() {
        cout << "Priority Queue: ";

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);

    pq.display();

    pq.dequeue();

    pq.display();

    return 0;
}