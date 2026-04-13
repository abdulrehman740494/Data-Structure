#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int idx = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pividx = partition(arr, start, end);

        quickSort(arr, start, pividx - 1);
        quickSort(arr, pividx + 1, end);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int value : arr)
    {
        cout << value << " ";
    }

    cout << endl;
    return 0;
}