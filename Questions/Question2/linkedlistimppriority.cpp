#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class PriorityQueue {
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        // Insert at beginning if queue is empty
        // or new value has higher priority
        if (front == nullptr || value < front->data) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node* temp = front;

            while (temp->next != nullptr &&
                   temp->next->data <= value) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Priority Queue is empty\n";
            return;
        }

        Node* temp = front;

        cout << front->data << " deleted\n";

        front = front->next;

        delete temp;
    }

    void display() {
        Node* temp = front;

        cout << "Priority Queue: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

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