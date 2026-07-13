#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *Head = NULL;
Node *Tail = NULL;

void insert(int value)
{
    Node *temp = new Node();

    temp->data = value;
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

    while(cur != NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
}

void reverseList()
{
    Node *cur = Head;
    Node *temp = NULL;

    while(cur != NULL)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;

        cur = cur->prev;
    }

    temp = Head;
    Head = Tail;
    Tail = temp;
}

void findMinimum()
{
    if(Head==NULL)
    {
        cout<<"List Empty\n";
        return;
    }

    int min = Head->data;

    Node *cur = Head->next;

    while(cur!=NULL)
    {
        if(cur->data < min)
            min = cur->data;

        cur = cur->next;
    }

    cout<<"Minimum = "<<min<<endl;
}


void findMaximum()
{
    if(Head==NULL)
    {
        cout<<"List Empty\n";
        return;
    }

    int max = Head->data;

    Node *cur = Head->next;

    while(cur!=NULL)
    {
        if(cur->data > max)
            max = cur->data;

        cur = cur->next;
    }

    cout<<"Maximum = "<<max<<endl;
}


int main()
{
    int choice, value;

    while(true)
    {
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Reverse";
        cout<<"\n4.Minimum";
        cout<<"\n5.Maximum";
        cout<<"\n6.Exit";

        cin>>choice;

        switch(choice)
        {
            case 1:

                cin>>value;
                insert(value);
                break;

            case 2:

                display();
                break;

            case 3:

                reverseList();
                cout<<"List Reversed\n";
                break;

            case 4:

                findMinimum();
                break;

            case 5:

                findMaximum();
                break;

            case 6:

                return 0;
        }
    }
}