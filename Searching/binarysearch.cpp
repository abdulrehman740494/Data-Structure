#include <iostream>
using namespace std;

int main() {
    int l = 0, r = 9, mid;
    int arr[10] = {1,5,6,11,49,77,88,91,99,101};
    int match;
    bool found = false;

    cout << "Enter a number: ";
    cin >> match;

    while (l <= r) {
        mid = (l + r) / 2;

        if (match == arr[mid]) {
            cout << "Found @ index " << mid;
            found = true;
            break;
        }

        if (match < arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    if (!found)
        cout << "Number not found!";
}