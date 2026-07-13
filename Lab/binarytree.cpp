#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *Root = NULL;

Node *Queue[100];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1;
}

void enqueue(Node *temp)
{
    if(front==-1)
        front=0;

    Queue[++rear]=temp;
}

Node* dequeue()
{
    Node *temp=Queue[front];

    if(front==rear)
        front=rear=-1;
    else
        front++;

    return temp;
}

void insertElement(int val)
{
    Node *temp=new Node();

    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;

    if(Root==NULL)
    {
        Root=temp;
        return;
    }

    front=rear=-1;

    enqueue(Root);

    while(!isEmpty())
    {
        Node *curr=dequeue();

        if(curr->left==NULL)
        {
            curr->left=temp;
            return;
        }
        else
            enqueue(curr->left);

        if(curr->right==NULL)
        {
            curr->right=temp;
            return;
        }
        else
            enqueue(curr->right);
    }
}

bool Search(Node *curr,int value)
{
    if(curr==NULL)
        return false;

    if(curr->data==value)
        return true;

    return Search(curr->left,value) ||
           Search(curr->right,value);
}

void InOrder(Node *curr)
{
    if(curr)
    {
        InOrder(curr->left);
        cout<<curr->data<<" ";
        InOrder(curr->right);
    }
}

int countNodes(Node *curr)
{
    if(curr==NULL)
        return 0;

    return 1 +
           countNodes(curr->left) +
           countNodes(curr->right);
}


int arr[100];
int index=0;

void storeInorder(Node *curr)
{
    if(curr==NULL)
        return;

    storeInorder(curr->left);

    arr[index++]=curr->data;

    storeInorder(curr->right);
}

void predecessorSuccessor(int val)
{
    index=0;

    storeInorder(Root);

    int pos=-1;

    for(int i=0;i<index;i++)
    {
        if(arr[i]==val)
        {
            pos=i;
            break;
        }
    }

    if(pos==-1)
    {
        cout<<"Value not found\n";
        return;
    }

    if(pos==0)
        cout<<"Predecessor : NULL\n";
    else
        cout<<"Predecessor : "<<arr[pos-1]<<endl;

    if(pos==index-1)
        cout<<"Successor : NULL\n";
    else
        cout<<"Successor : "<<arr[pos+1]<<endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Insert Element\n";
        cout << "2. Display Inorder\n";
        cout << "3. Search Element\n";
        cout << "4. Find Predecessor & Successor\n";
        cout << "5. Count Total Nodes\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter Value: ";
            cin >> val;

            insertElement(val);
            break;
        }

        case 2:
        {
            if (Root == NULL)
            {
                cout << "Tree is Empty.\n";
            }
            else
            {
                cout << "Inorder Traversal: ";
                InOrder(Root);
                cout << endl;
            }
            break;
        }

        case 3:
        {
            if (Root == NULL)
            {
                cout << "Tree is Empty.\n";
                break;
            }

            int val;
            cout << "Enter Value to Search: ";
            cin >> val;

            if (Search(Root, val))
                cout << "Value Found.\n";
            else
                cout << "Value Not Found.\n";

            break;
        }

        case 4:
        {
            if (Root == NULL)
            {
                cout << "Tree is Empty.\n";
                break;
            }

            int val;
            cout << "Enter Value: ";
            cin >> val;

            predecessorSuccessor(val);

            break;
        }

        case 5:
        {
            cout << "Total Nodes = " << countNodes(Root) << endl;
            break;
        }

        case 6:
        {
            cout << "Exiting Program...\n";
            break;
        }

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}