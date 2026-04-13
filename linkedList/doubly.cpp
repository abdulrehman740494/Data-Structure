#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *list = NULL;

void insert(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    if (list == NULL)
    {
        list = temp;
        return;
    }

    Node *cur = list;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
}

void deleteElement(int value)
{
    if (list == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *cur = list;

    if (value == cur->data)
    {
        list = list->next;

        if (list != NULL)
            list->prev = NULL;  // naya head ka prev NULL karo

        free(cur);
        cout << "Deleted " << value << endl;
        return;
    }

    // Case 2: baaki nodes mein dhundo
    Node *prev = list;
    cur = cur->next;

    while (cur != NULL)
    {
        if (value == cur->data)
        {
            prev->next = cur->next;  // pichla node aage jump kare

            if (cur->next != NULL)
                cur->next->prev = prev;  // agla node peeche jump kare

            free(cur);
            cout << "Deleted " << value << endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "Value " << value << " not found" << endl;
}

void search(int value)
{
    Node *cur = list;
    int position = 0;

    while (cur != NULL)
    {
        if (cur->data == value)
        {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        cur = cur->next;
        position++;
    }
    cout << "Value " << value << " not found in list" << endl;
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