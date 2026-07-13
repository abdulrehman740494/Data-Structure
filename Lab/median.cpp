#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *middle1;
    Node *middle2;
    Node *right;
};

Node *Root = NULL;


int findMedian(int start, int end)
{
    return (start + end) / 2;
}


Node* createTree(int arr[], int start, int end)
{
    if(start > end)
        return NULL;

    int mid = findMedian(start, end);

    Node *temp = new Node();

    temp->data = arr[mid];

    temp->left = NULL;
    temp->middle1 = NULL;
    temp->middle2 = NULL;
    temp->right = NULL;

    int total = end - start + 1;

    if(total == 1)
        return temp;

    int q = total / 4;

    if(q == 0)
        q = 1;


    int s1Start = start;
    int s1End = mid - q - 1;


    int s2Start = mid - q;
    int s2End = mid - 1;


    int s3Start = mid + 1;
    int s3End = mid + q;


    int s4Start = mid + q + 1;
    int s4End = end;

    if(s1Start <= s1End)
        temp->left = createTree(arr,s1Start,s1End);

    if(s2Start <= s2End)
        temp->middle1 = createTree(arr,s2Start,s2End);

    if(s3Start <= s3End)
        temp->middle2 = createTree(arr,s3Start,s3End);

    if(s4Start <= s4End)
        temp->right = createTree(arr,s4Start,s4End);

    return temp;
}



void display(Node *curr)
{
    if(curr == NULL)
        return;

    cout << curr->data << " ";

    display(curr->left);
    display(curr->middle1);
    display(curr->middle2);
    display(curr->right);
}


void printLevel(Node *curr, int level)
{
    if(curr == NULL)
        return;

    cout << "Node = " << curr->data
         << "  Level = " << level << endl;

    printLevel(curr->left, level + 1);
    printLevel(curr->middle1, level + 1);
    printLevel(curr->middle2, level + 1);
    printLevel(curr->right, level + 1);
}


int maxValue(int a, int b)
{
    if(a > b)
        return a;

    return b;
}

int height(Node *curr)
{
    if(curr == NULL)
        return -1;

    int h1 = height(curr->left);
    int h2 = height(curr->middle1);
    int h3 = height(curr->middle2);
    int h4 = height(curr->right);

    int ans = maxValue(h1, h2);
    ans = maxValue(ans, h3);
    ans = maxValue(ans, h4);

    return ans + 1;
}


void printHeight(Node *curr)
{
    if(curr == NULL)
        return;

    cout << "Node = " << curr->data
         << "  Height = " << height(curr) << endl;

    printHeight(curr->left);
    printHeight(curr->middle1);
    printHeight(curr->middle2);
    printHeight(curr->right);
}