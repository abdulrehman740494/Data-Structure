#include <iostream>
#include <stdlib.h>
#include <cctype>
using namespace std;
struct stack
{
    char data;
    stack *next;
};
stack *top = NULL;
char postfix[100];
char op[13] = {'%', '/', '*', '+', '-', '<', '>', '&', '|', '=', '!', '(', ')'};
int p = 0;
void push(char value)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->data = value;
    temp->next = top;
    top = temp;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Undeflow.";
        return;
    }
    stack *temp = top;
    top = top->next;
    free(temp);
}
void Display()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.";
        return;
    }

    stack *curr = top;
    while (curr != NULL)
    {
        cout << curr->data;
        curr = curr->next;
    }
}
int precedence(char value)
{
    switch (value)
    {
    case '%':
        return 6;
        break;
    case '/':
        return 6;
        break;
    case '*':
        return 6;
        break;
    case '+':
        return 5;
        break;
    case '-':
        return 5;
        break;
    case '<':
        return 4;
        break;
    case '>':
        return 4;
        break;
    case '!':
        return 3;
        break;
    case '=':
        return 3;
        break;
    case '&':
        return 2;
        break;
    case '|':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int IsOperand(char x)
{
    if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
        return 1;

    return 0;
}
char peek()
{
     if (top == NULL)
        return '\0';

    return top->data;
}
void comparison(char x)
{
    if (x == '(')
    {
        push(x);
        return;
    }
    if (x == ')')
    {
        while (top != NULL && top->data != '(')
        {
            postfix[p++] = top->data;
            pop();
        }
        pop();
        return;
    }
     if(IsOperand(x))
    {
        postfix[p++] = x;
    }
    else
    {
        while(top != NULL && precedence(top->data) >= precedence(x))
        {
            postfix[p++] = top->data;
            pop();
        }

        push(x);
    }

   
}
int evaluatepostfix()
{
    int stack[100];
    int t = -1;
    for (int i = 0; i < p; i++)
    {
        char c = postfix[i];
        if (isdigit(c))
        {
            stack[++t] = c - 48;
        }
        else
        {
            if (t < 1)
            {
                cout << "Invalid Expression. ";
                return 0;
            }
            int b = stack[t--];
            int a = stack[t--];
            int result = 0;
            switch (c)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '/':
                result = a / b;
                break;
            case '*':
                result = a * b;
                break;
            case '%':
                result = a % b;
                break;
            default:
                cout << "Invalid Operator used .";
                return 0;
                break;
            }
            stack[++t] = result;
        }
    }
    return stack[t];
}
// MAIN MENU
int main()
{
    while (true)
    {
        char value;
        int choice;

        cout << "\nMenu:\n1. Enter single character\n2. Display Stack\n3. Show Postfix Expression\n4. Evaluate Postfix\n5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter character: ";
            cin >> value;
            comparison(value);
            break;
        case 2:
            Display();
            break;
        case 3:
            while (top != NULL)
            {
                postfix[p++] = top->data;
                pop();
            }
            cout << "Postfix Expression: ";
            for (int i = 0; i < p; i++)
                cout << postfix[i];
            cout << endl;
            break;
        case 4:
            // pop remaining operators
            while (top != NULL)
            {
                postfix[p++] = top->data;
                pop();
            }
            cout << "Postfix Expression: ";
            for (int i = 0; i < p; i++)
            {
                cout << postfix[i];
            }
            cout << "\nEvaluation Result: " << evaluatepostfix() << endl;

            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
