#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;

        if (front == nullptr) {
            front = rear = newNode;
        }
        else {
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;

        cout << front->data << " deleted\n";

        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        else
            front->prev = nullptr;

        delete temp;
    }

    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = rear;

        cout << rear->data << " deleted\n";

        rear = rear->prev;

        if (rear == nullptr)
            front = nullptr;
        else
            rear->next = nullptr;

        delete temp;
    }

    void display() {
        Node* temp = front;

        cout << "Deque: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

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