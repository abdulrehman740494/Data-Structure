#include <iostream>
using namespace std;

int main (){
    int array[5] = {1,6,12,75,9};
    bool found = false;
    int match ;
    cout << "Enter number to search: ";
    cin >> match;

    for (int i = 0; i < 5; i++)
    {
        if (array[i] == match)
        {
            cout << "Number found at index " << i;
            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "Number not found!";
    }

    return 0;
}