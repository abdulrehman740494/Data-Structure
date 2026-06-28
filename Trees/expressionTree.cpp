#include <iostream>
using namespace std;

//================ STACK FOR OPERATORS =================

struct Node
{
    char value;
    Node* next;
};

Node* Top = NULL;

void push(char operatorSymbol)
{
    Node* temp = new Node();

    temp->value = operatorSymbol;
    temp->next = Top;

    Top = temp;
}

char peek()
{
    if (Top == NULL)
        return '\0';

    return Top->value;
}

char pop()
{
    if (Top == NULL)
    {
        return '\0';
    }

    Node* tempNode = Top;

    char removedOperator = tempNode->value;

    Top = Top->next;

    delete tempNode;

    return removedOperator;
}

int getPrecedence(char operatorSymbol)
{
    switch (operatorSymbol)
    {
    case '*':
    case '/':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

bool isOperand(char currentCharacter)
{
    if ((currentCharacter >= 'A' && currentCharacter <= 'Z') ||
        (currentCharacter >= 'a' && currentCharacter <= 'z') ||
        (currentCharacter >= '0' && currentCharacter <= '9'))
    {
        return true;
    }

    return false;
}

//================ INFIX TO POSTFIX =================

void infixToPostfix(char expression[], char postfix[])
{
    int currentIndex = 0;
    int k = 0;

    while (expression[currentIndex] != '\0')
    {
        char currentCharacter = expression[currentIndex];

        if (isOperand(currentCharacter))
        {
            postfix[k++] = currentCharacter;
        }
        else
        {
            while (Top != NULL &&
                   getPrecedence(peek()) >=
                   getPrecedence(currentCharacter))
            {
                postfix[k++] = pop();
            }

            push(currentCharacter);
        }

        currentIndex++;
    }

    while (Top != NULL)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

//================ EXPRESSION TREE =================

// Tree Node
struct ETNode
{
    char data;
    ETNode* left;
    ETNode* right;
};

// Stack for Tree Nodes
struct TreeStack
{
    ETNode* data;
    TreeStack* next;
};

TreeStack* treeTop = NULL;

void pushTreeNode(ETNode* node)
{
    TreeStack* temp = new TreeStack;

    temp->data = node;
    temp->next = treeTop;

    treeTop = temp;
}

ETNode* popTreeNode()
{
    if (treeTop == NULL)
        return NULL;

    TreeStack* temp = treeTop;

    ETNode* node = temp->data;

    treeTop = treeTop->next;

    delete temp;

    return node;
}

ETNode* createNode(char value)
{
    ETNode* temp = new ETNode();

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Build Tree from Postfix
ETNode* buildExpressionTree(char postfix[])
{
    int i = 0;

    while (postfix[i] != '\0')
    {
        char currentCharacter = postfix[i];

        // Operand
        if (isOperand(currentCharacter))
        {
            pushTreeNode(createNode(currentCharacter));
        }

        // Operator
        else
        {
            ETNode* rightChild = popTreeNode();
            ETNode* leftChild = popTreeNode();

            ETNode* newRoot = createNode(currentCharacter);

            newRoot->left = leftChild;
            newRoot->right = rightChild;

            pushTreeNode(newRoot);
        }

        i++;
    }

    return popTreeNode();
}

//================ TRAVERSALS =================

// Inorder Traversal
void inorder(ETNode* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

// Preorder Traversal
void preorder(ETNode* root)
{
    if (root == NULL)
        return;

    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(ETNode* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

//================ MAIN =================

int main()
{
    char expression[100];
    char postfix[100];

    cout << "Enter Infix Expression: ";
    cin >> expression;

    infixToPostfix(expression, postfix);

    cout << "Postfix Expression: " << postfix << endl;

    // Build Expression Tree
    ETNode* root = buildExpressionTree(postfix);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}