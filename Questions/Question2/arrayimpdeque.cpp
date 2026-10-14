#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    void insertFront(int value) {
        if (front == 0) {
            cout << "Cannot insert at front\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        }
        else {
            front--;
        }

        arr[front] = value;
    }

    void insertRear(int value) {
        if (rear == SIZE - 1) {
            cout << "Cannot insert at rear\n";
            return;
        }

        if (rear == -1) {
            front = rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;
    }

    void deleteFront() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << arr[front] << " deleted from front\n";

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void deleteRear() {
        if (rear == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << arr[rear] << " deleted from rear\n";

        if (front == rear)
            front = rear = -1;
        else
            rear--;
    }

    void display() {
        if (front == -1) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque: ";

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.insertRear(20);
    dq.insertRear(30);
    dq.insertFront(10);

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    return 0;
}