
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Vertex;
struct Edge;
struct stack
{
    Vertex *data;
    stack *next;
};
stack *Top = NULL;
void push(Vertex *value)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->data = value;
    temp->next = NULL;
    if (Top == NULL)
    {
        Top = temp;
        return;
    }
    temp->next = Top;
    Top = temp;
}
Vertex *pop()
{
    if (Top == NULL)
    {
        cout << "Stack underflow";
        return NULL;
    }

    stack *temp = Top;
    Vertex *value;
    value = temp->data;
    Top = Top->next;
    free(temp);
    return value;
}
struct dqueue
{
    Vertex *data;
    dqueue *next;
};
dqueue *qrare = NULL;
dqueue *qfront = NULL;

void Enqueue(Vertex *value)
{
    if (value == NULL)
    {
        return;
    }

    dqueue *temp = (dqueue *)malloc(sizeof(dqueue));
    temp->data = value;
    temp->next = NULL;
    if (qrare == NULL && qfront == NULL)
    {
        qrare = temp;
        qfront = qrare;
    }
    else
    {
        qrare->next = temp;
        qrare = qrare->next;
    }
}

Vertex *Dequeue()
{
    if (qfront == NULL)
    {
        return NULL;
    }
    dqueue *temp = qfront;
    Vertex *value = temp->data;

    // if only one node.
    if (qrare == qfront)
    {

        qrare = NULL;
        qfront = NULL;
    }
    else
    {
        qfront = qfront->next;
    }
    free(temp);
    return value;
}
struct Vertex
{
    char data;
    Vertex *vnext;
    Edge *Edgelist;
    bool visited;
    Vertex *Parent;
};
struct Edge
{
    Edge *enext;
    Vertex *v;
};
Vertex *graph = NULL;
void addVertex(char value)
{
    Vertex *temp = (Vertex *)malloc(sizeof(Vertex));
    temp->data = value;
    temp->vnext = NULL;
    temp->Edgelist = NULL;
    temp->visited = false;
    temp->Parent = NULL;
    if (graph == NULL)
    {
        graph = temp;
        return;
    }
    Vertex *curr = graph;
    while (curr->vnext != NULL)
    {
        curr = curr->vnext;
    }
    curr->vnext = temp;
}
Vertex *address(char a)
{
    Vertex *curr = graph;
    while (curr != NULL)
    {
        if (a == curr->data)
        {
            return curr;
        }
        curr = curr->vnext;
    }
    cout << "The vertex does not exist." << endl;
    return NULL;
}
void addEdge(char vertex1, char vertex2)
{
    Vertex *v1 = address(vertex1);
    Vertex *v2 = address(vertex2);
    if (v1 == NULL || v2 == NULL)
    {
        cout << "Vertex does not Exist." << endl;
        return;
    }
    // V1 - v2 to edge
    Edge *temp1 = (Edge *)malloc(sizeof(Edge));
    temp1->v = v2;
    temp1->enext = NULL;
    if (v1->Edgelist == NULL)
    {
        v1->Edgelist = temp1;
    }
    else
    {
        Edge *curr1 = v1->Edgelist;
        while (curr1->enext != NULL)
        {
            curr1 = curr1->enext;
        }
        curr1->enext = temp1;
    }
    // v2 to v1 edge
    Edge *temp2 = (Edge *)malloc(sizeof(Edge));
    temp2->v = v1;
    temp2->enext = NULL;
    if (v2->Edgelist == NULL)
    {
        v2->Edgelist = temp2;
    }
    else
    {
        Edge *curr2 = v2->Edgelist;
        while (curr2->enext != NULL)
        {
            curr2 = curr2->enext;
        }
        curr2->enext = temp2;
    }
}
void display()
{
    Vertex *curr = graph;
    Edge *ecurr;
    if (graph != NULL)
    {
        while (curr != NULL)
        {

            cout << curr->data << " | ";
            ecurr = curr->Edgelist;
            while (ecurr != NULL)
            {
                cout << ecurr->v->data << " ";
                ecurr = ecurr->enext;
            }
            curr = curr->vnext;

            cout << endl;
        }
    }
    else
    {
        cout << "Graph is empty" << endl;
    }
}
void Degree()
{
    Vertex *v = graph;
    while (v != NULL)
    {
        Edge *e = v->Edgelist;
        int count = 0;
        while (e != NULL)
        {
            count++;
            //

            e = e->enext;
        }
        cout << "Degree of Vertix : " << count << endl;
        v = v->vnext;
    }
}
void BFS()
{
    if (graph == NULL)
    {
        return;
    }
    Vertex *t = graph;
    while (t != NULL)
    {
        t->visited = false;
        t = t->vnext;
    }
    Vertex *ver = graph;

    Enqueue(ver);
    ver->visited = true;

    while (qfront != NULL)
    {
        Vertex *output = Dequeue();

        if (output == NULL)
        {
            continue;
        }
        cout << output->data << " ";

        Edge *e = output->Edgelist;

        while (e != NULL)
        {
            if (e->v->visited != true)
            {
                e->v->visited = true;
                Enqueue(e->v);
            }
            e = e->enext;
        }
    }
}

void DFS()
{
    if (graph == NULL)
    {
        return;
    }
    Vertex *t = graph;
    while (t != NULL)
    {
        t->visited = false;
        t = t->vnext;
    }
    Vertex *v1 = graph;
    push(v1);
    while (Top != NULL)
    {
        Vertex *output = pop();
        if (output->visited != true)
        {
            cout << output->data << " ";
            output->visited = true;
        }
        Edge *e = output->Edgelist;
        while (e != NULL)
        {
            if (e->v->visited != true)
            {
                push(e->v);
            }
            e = e->enext;
        }
    }
}
void RemoveVertex(char value)
{
    Vertex *V = graph;
    while (V != NULL)
    {
        Edge *e = V->Edgelist;
        Edge *eprev = NULL;

        while (e != NULL)
        {
            if (e->v->data == value)
            {
                Edge *temp = e;
                e = e->enext;
                if (eprev == NULL)
                {
                    V->Edgelist = e;
                }
                else
                {
                    eprev->enext = e;
                }
                free(temp);
            }
            else
            {
                eprev = e;
                e = e->enext;
            }
        }
        V = V->vnext;
    }
    V = graph;
    Vertex *Vprev = NULL;
    while (V != NULL)
    {
        if (value == V->data)
        {
            Edge *e = V->Edgelist;
            while (e != NULL)
            {
                Edge *temp = e;
                e = e->enext;
                free(temp);
            }
            if (Vprev == NULL)
            {
                graph = V->vnext;
            }
            else
            {
                Vprev->vnext = V->vnext;
            }
            free(V);
            return;
        }
        Vprev = V;
        V = V->vnext;
    }
}
Vertex *findVertix(char v)
{
    Vertex *temp = graph;
    while (temp != NULL)
    {
        if (temp->data == v)
        {
            return temp;
        }
        temp = temp->vnext;
    }
    return NULL;
}
void Print_path(Vertex *v)
{
    if (v == NULL)
    {
        return;
    }
    Print_path(v->Parent);
    cout << v->data << " ";
}

void find_path(char vert1, char vert2)
{
    Vertex *source = findVertix(vert1);
    Vertex *destination = findVertix(vert2);

    if (!source || !destination)
    {
        cout << "No Vertex Exist";
        return;
    }

    // reset
    Vertex *temp = graph;
    while (temp)
    {
        temp->visited = false;
        temp->Parent = NULL;
        temp = temp->vnext;
    }

    push(source);

    bool found = false;

    while (Top != NULL)
    {
        Vertex *output = pop();

        if (output->visited)
            continue;

        output->visited = true;

        if (output == destination)
        {
            found = true;
            break;
        }

        Edge *e = output->Edgelist;

        while (e)
        {
            if (!e->v->visited)
            {
                e->v->Parent = output;
                push(e->v);
            }
            e = e->enext;
        }
    }

    if (!found)
    {
        cout << "NO path found";
        return;
    }

    Print_path(destination);
}
int main()
{
    int choice;
    char val, num1, num2;

    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Vertex \n2. Display \n3. Add Edge \n4. DFS \n5. Degree \n6. BFS \n7. Remove Vertex\n8. Path \n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            addVertex(val);
            break;

        case 2:
            display();
            break;

        case 3:
            cout << "Enter vertex I:";
            cin >> num1;
            cout << "Enter vertex II to attach:";
            cin >> num2;
            addEdge(num1, num2);
            break;

        case 4:
            DFS();
            break;

        case 5:
            Degree();
            break;
        case 6:
            BFS();
            break;

        case 7:
            cout << "Enter a Vertex to Delete: ";
            cin >> val;
            RemoveVertex(val);
            break;
        case 8:
            cout << "Enter first  Vertex 1: ";
            cin >> num1;
            cout << "Enter second Vertex 2: ";
            cin >> num2;
            find_path(num1, num2);
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}