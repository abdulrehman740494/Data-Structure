#include <iostream>
#include <cstdlib>
using namespace std;

int arr[100];
int MAXsize = sizeof(arr) / sizeof(arr[0]);
int heapsize = 0;

void swapValues(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void upHeapify(int i)
{
    if (i == 0)
        return;

    int parent = (i - 1) / 2;

    if (arr[parent] < arr[i])
    {
        swapValues(arr[parent], arr[i]);
        upHeapify(parent);
    }
}

void downHeapify(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heapsize && arr[left] > arr[largest])
        largest = left;

    if (right < heapsize && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swapValues(arr[i], arr[largest]);
        downHeapify(largest);
    }
}

void insertElement(int val)
{
    if (heapsize == MAXsize)
    {
        cout << "Heap Overflow\n";
        return;
    }

    arr[heapsize] = val;
    heapsize++;                  
    upHeapify(heapsize - 1);     
}

void deleteRoot()
{
    if (heapsize == 0)
    {
        cout << "Heap Underflow\n";
        return;
    }

    cout << "Deleted Root: " << arr[0] << endl;

    arr[0] = arr[heapsize - 1];
    heapsize--;

    if (heapsize > 0){
        downHeapify(0);
    }
}

void display()
{
    if (heapsize == 0)
    {
        cout << "Heap is Empty\n";
        return;
    }

    for (int i = 0; i < heapsize; i++)
        cout << arr[i] << " ";

    cout << endl;
}

void heapSort()
{
    if (heapsize == 0)
    {
        cout << "Heap is Empty\n";
        return;
    }

    int tempSize = heapsize;

    while (heapsize > 1)
    {
        swapValues(arr[0], arr[heapsize - 1]);
        heapsize--;
        downHeapify(0);
    }

    cout << "Sorted Array:\n";

    for (int i = 0; i < tempSize; i++)
        cout << arr[i] << " ";

    cout << endl;

    // Restore heap
    heapsize = tempSize;

    for (int i = heapsize / 2 - 1; i >= 0; i--)
        downHeapify(i);
}

int main()
{
    int choice, val;

    while (true)
    {
        cout << "\n1.Insert\n2.Delete Root\n3.Display\n4.Heap Sort\n5.Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertElement(val);
            break;

        case 2:
            deleteRoot();
            break;

        case 3:
            display();
            break;

        case 4:
            heapSort();
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}