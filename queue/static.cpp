#include <iostream>
using namespace std;

const int SIZE = 5;
int queue[SIZE];
int front = 0;
int rear = -1;
int count = 0;

void enQueue(int value) {
    if (count == SIZE) {
        cout << "Queue is full!" << endl;
        return;
    }
    rear++;              
    queue[rear] = value;
    count++;
}

void deQueue() {
    if (count == 0) {
        cout << "Queue is empty" << endl;
        return;
    }
    int value = queue[front];
    front++;             
    count--;
    cout << "Dequeued: " << value << endl;
}

void display() {
    if (count == 0) {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    enQueue(10);
    enQueue(20);
    enQueue(30);
    display();     // 10 20 30

    deQueue();
    display();     // 20 30

    enQueue(40);
    enQueue(50);
    display();     // 20 30 40 50

    while (count > 0) {
        deQueue();
    }
    display();     // Queue is empty

    return 0;
}