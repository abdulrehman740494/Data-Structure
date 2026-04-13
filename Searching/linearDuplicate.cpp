#include <iostream>
using namespace std;

int main (){

    int array[6] = {1,6,12,75,12,12};
    bool found = false;
    int match;

    cout << "Enter number to search: ";
    cin >> match;

    cout << "Number found at index: ";

    for (int i = 0; i < 6; i++)
    {
        if (array[i] == match)
        {
            cout << i << " ";
            found = true;
        }
    }

    if (found == false)
    {
        cout << "Number not found!";
    }

    return 0;
}