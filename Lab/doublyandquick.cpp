#include <iostream>
using namespace std;

struct Node
{
    int index;
    int data;
    Node *next;
    Node *prev;
};

Node *Head = NULL;
Node *Tail = NULL;
int currentIndex = 0;


void insert(int value)
{
    Node *temp = new Node();

    temp->data = value;
    temp->index = currentIndex++;
    temp->next = NULL;
    temp->prev = NULL;

    if (Head == NULL)
    {
        Head = Tail = temp;
        return;
    }

    Tail->next = temp;
    temp->prev = Tail;
    Tail = temp;
}


void display()
{
    Node *cur = Head;

    while (cur != NULL)
    {
        cout << "[" << cur->index << "] "
             << cur->data << " <-> ";

        cur = cur->next;
    }

    cout << "NULL\n";
}


void swapData(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


Node* partition(Node *start, Node *end)
{
    int pivot = end->data;

    Node *idx = start->prev;

    for (Node *j = start; j != end; j = j->next)
    {
        if (j->data < pivot)
        {
            if (idx == NULL)
                idx = start;
            else
                idx = idx->next;

            swapData(idx, j);
        }
    }

    if (idx == NULL)
        idx = start;
    else
        idx = idx->next;

    swapData(idx, end);

    return idx;
}


void quickSort(Node *start, Node *end)
{
    if (start != NULL &&
        end != NULL &&
        start != end &&
        start != end->next)
    {
        Node *pivot = partition(start, end);

        quickSort(start, pivot->prev);

        quickSort(pivot->next, end);
    }
}


int main()
{
    int choice, value;

    while (true)
    {
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Quick Sort";
        cout << "\n4.Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter Value : ";
            cin >> value;

            insert(value);

            break;

        case 2:

            display();

            break;

        case 3:

            quickSort(Head, Tail);

            cout << "List Sorted Successfully.\n";

            break;

        case 4:

            return 0;

        default:

            cout << "Invalid Choice\n";
        }
    }
}