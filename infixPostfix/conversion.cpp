#include <iostream>
using namespace std;

// Node of Stack
struct Node
{
    char value;      // Stores operator (+, -, *, etc.)
    Node* next;      // Points to next node
};

// Top pointer of stack
Node* Top = NULL;


// Function to insert an operator into stack
void push(char operatorSymbol)
{
    Node* temp = new Node();

    temp->value = operatorSymbol;
    temp->next = Top;

    Top = temp;
}


// Function to see top element without removing it
char peek()
{
    if (Top == NULL)
        return '\0';

    return Top->value;
}


// Function to remove top element from stack
char pop()
{
    if (Top == NULL)
    {
        cout << "Stack Underflow\n";
        return '\0';
    }

    Node* tempNode = Top;

    char removedOperator = tempNode->value;

    Top = Top->next;

    delete tempNode;

    return removedOperator;
}


// Function to return precedence of operators
int getPrecedence(char operatorSymbol)
{
    switch (operatorSymbol)
    {
        case '*':
        case '/':
            return 6;

        case '+':
        case '-':
            return 5;

        case '=':
        case '!':
            return 4;

        case '<':
        case '>':
            return 3;

        case '&':
            return 2;

        case '|':
            return 1;

        default:
            return 0;
    }
}


// Checks whether character is operand or not
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


// Converts Infix expression into Postfix
void infixToPostfix(char expression[])
{
    int currentIndex = 0;

    while (expression[currentIndex] != '\0')
    {
        // Current character being processed
        char currentCharacter = expression[currentIndex];

        // If operand, print directly
        if (isOperand(currentCharacter))
        {
            cout << currentCharacter;
        }

        // If operator
        else
        {
            // Pop all operators having higher or equal precedence
            while (Top != NULL &&
                   getPrecedence(peek()) >=
                   getPrecedence(currentCharacter))
            {
                cout << pop();
            }

            // Push current operator
            push(currentCharacter);
        }

        currentIndex++;
    }

    // Print remaining operators from stack
    while (Top != NULL)
    {
        cout << pop();
    }
}


int main()
{
    char expression[100];

    cout << "Enter Infix Expression: ";
    cin >> expression;

    cout << "Postfix Expression: ";

    infixToPostfix(expression);

    return 0;
}