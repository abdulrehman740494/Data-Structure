#include <iostream>
using namespace std;

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
        cout << "Stack Underflow\n";
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


void infixToPostfix(char expression[])
{
    int currentIndex = 0;

    while (expression[currentIndex] != '\0')
    {
        char currentCharacter = expression[currentIndex];

        if (isOperand(currentCharacter))
        {
            cout << currentCharacter;
        }

        else
        {
            while (Top != NULL &&
                   getPrecedence(peek()) >=
                   getPrecedence(currentCharacter))
            {
                cout << pop();
            }

            push(currentCharacter);
        }
        currentIndex++;
    }

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