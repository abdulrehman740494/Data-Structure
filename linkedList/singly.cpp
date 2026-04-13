#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *list = NULL;

void insert(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;

    if (list == NULL)
    {
        list = temp;
    }
    else
    {
        Node *cur = list;

        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = temp;
    }
}

void display()
{
    Node *cur = list;

    while (cur != NULL)
    {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

void deleteElement(int value)
{
    if (list == NULL)
    {
        cout << "List is empty ";
        return;
    }

    Node *cur = list;
    if (value = list->data)
    {
        list = list->next;
        free(cur);
        return;
    }

    Node *prev = list;
    cur = cur->next;
    while (cur != NULL)
    {
        if (value == cur->data)
        {
            prev->next = cur->next;
            free(cur);
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
}

bool search(int value)
{

    Node *cur = list;
    int position = 0;

    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cout << "Value " << value << " found at position " << position << endl;
            return true;
        }

        cur = cur->next;
        position++;
    }

    cout << "Value " << value << " not found in list" << endl;
    return false;
}

int main()
{
    int choice, val;

    while (true)
    {
        cout << "\n=== LINKED LIST OPERATIONS ===" << endl;
        cout << "1- Insert (at end)" << endl;
        cout << "2- Display" << endl;
        cout << "3- Search" << endl;
        cout << "4- Delete" << endl;
        cout << "5- Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> val;
            insert(val);
            cout << "✓ Inserted " << val << endl;
        }
        else if (choice == 2)
        {
            cout << "List: ";
            display();
        }
        else if (choice == 3)
        {
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
        }
        else if (choice == 4)
        {
            cout << "Enter the value to delete : ";
            cin >> val;
            deleteElement(val);
            cout << " Deleted " << val << endl;
        }
        else if (choice == 5)
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}