#include <iostream>
using namespace std;

struct Node
{
    float data;
    Node *left;
    Node *right;
};

// Heap Array
float arr[100];
int heapSize = 0;

// Root of Binary Tree
Node *Root = NULL;

// Insert into array (Heap style)
void insertElement(float val)
{
    if (heapSize == 100)
    {
        cout << "Tree is Full\n";
        return;
    }

    arr[heapSize] = val;
    heapSize++;
}

// Build Binary Tree from Array
Node* BuildTree(int index)
{
    if (index >= heapSize)
        return NULL;

    Node *temp = new Node();

    temp->data = arr[index];
    temp->left = BuildTree(2 * index + 1);
    temp->right = BuildTree(2 * index + 2);

    return temp;
}

// Mirror Function
void Mirror(Node *curr)
{
    if (curr == NULL)
        return;

    Node *temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;

    Mirror(curr->left);
    Mirror(curr->right);
}

// Traversals
void PreOrder(Node *curr)
{
    if (curr == NULL)
        return;

    cout << curr->data << " ";
    PreOrder(curr->left);
    PreOrder(curr->right);
}

void InOrder(Node *curr)
{
    if (curr == NULL)
        return;

    InOrder(curr->left);
    cout << curr->data << " ";
    InOrder(curr->right);
}

void PostOrder(Node *curr)
{
    if (curr == NULL)
        return;

    PostOrder(curr->left);
    PostOrder(curr->right);
    cout << curr->data << " ";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Insert Element\n";
        cout << "2. Build Binary Tree\n";
        cout << "3. Display Tree\n";
        cout << "4. Mirror Tree\n";
        cout << "5. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            float val;
            cout << "Enter Value : ";
            cin >> val;
            insertElement(val);
            break;
        }

        case 2:
        {
            Root = BuildTree(0);
            cout << "Binary Tree Created Successfully.\n";
            break;
        }

        case 3:
        {
            if (Root == NULL)
            {
                cout << "Tree is Empty.\n";
                break;
            }

            int ch;

            cout << "\n1. PreOrder";
            cout << "\n2. InOrder";
            cout << "\n3. PostOrder";
            cout << "\nEnter Choice : ";
            cin >> ch;

            if (ch == 1)
                PreOrder(Root);

            else if (ch == 2)
                InOrder(Root);

            else if (ch == 3)
                PostOrder(Root);

            else
                cout << "Invalid Choice";

            cout << endl;
            break;
        }

        case 4:
        {
            if (Root == NULL)
            {
                cout << "Build the Tree First.\n";
                break;
            }

            Mirror(Root);
            cout << "Mirror Tree Created Successfully.\n";
            break;
        }

        case 5:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}