#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = top;
    top = temp;          
}

void pop() {
    if (top == NULL) {
        cout << "Stack underflow";
        return;
    }
    Node* curr = top;
    cout << top->data << " has been popped";
    top = top->next;     
    free(curr);
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty";
        return;
    }
    Node* curr = top;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (choice != 4) {     
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value" << endl;
            cin >> value;
            push(value);
        }
        if (choice == 2)
            pop();
        if (choice == 3)
            display();
        if (choice == 4)
            break;
    }

    return 0;
}