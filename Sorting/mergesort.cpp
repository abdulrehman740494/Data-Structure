#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i = l;       
    int j = m + 1;   
    int k = 0;     

    int temp[100];

    // Compare and store smaller element
    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (left side)
    while(i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements (right side)
    while(j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy back to original array
    for(int x = 0; x < k; x++)
    {
        arr[l + x] = temp[x];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}