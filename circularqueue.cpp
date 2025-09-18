#include<iostream>
using namespace std;

const int s = 10;

class circularqueue {
    int a[s];
    int front, rear;
public:
    circularqueue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int v) {
        if ((rear + 1) % s == front) {
            cout << "\nqueue is full\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % s;
        }
        cout << "enqueued element : " << v;
        a[rear] = v;
    }
    void dequeue() {
        if (front == -1) {
            cout << "\nqueue is empty\n";
            return;
        }
        cout << "\ndeleted element: " << a[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % s;
        }
    }
    void display() {
        if (front == -1) {
            cout << "\nqueue is empty so, can't able to display";
            return;
        }
        cout << "\nelement in the queue\n";
        int i = front;
        while (true) {
            cout << a[i] << "\t";
            if (i == rear)
                break;
            i = (i + 1) % s;
        }
    }
};

int main() {
    circularqueue q;
    int choice, n;
    cout << "\nsize of the queue is " << s;
    do {
        cout << "\nmentu:\n";
        cout << "\n1.enqueue\n";
        cout << "\n2.dequeue\n";
        cout << "\n3.display\n";
        cout << "\n4.exit\n";
        cout << "enter your choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nenter the value to enqueue:";
            cin >> n;
            q.enqueue(n);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "exiting...";
            break;
        default:
            cout << "\ninvalid choice!";
        }
    } while (choice != 4);
}
