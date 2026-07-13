
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enQueue(int val){

    Node *temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if (front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void deQueue(){

    if (front == NULL){
        cout << "Queue is empty" << endl;
        return;
    }
    Node *curr = front;
    front = front->next;

    if (front == NULL){
        rear = NULL;
    }
    delete curr;
}

void display(){
    if (front == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *curr = front;
    while (curr!=NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}

int main() {

    enQueue(10);
    enQueue(23);
    enQueue(44);
    display();

    deQueue();
    display();

    while (front != NULL) {
        deQueue();
    }
    display();

    return 0;
}
