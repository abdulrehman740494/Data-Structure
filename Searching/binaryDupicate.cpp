#include <iostream>
using namespace std;

int main() {

    int arr[10] = {1,5,6,11,41,47,88,88,88,101};
    int match;
    cout << "Enter number: ";
    cin >> match;

    int l = 0, r = 9, mid;
    bool found = false;

    while (l <= r) {
        mid = (l + r) / 2;

        if (arr[mid] == match) {
            found = true;

            cout << "Value found at index: ";

            // finding left side duplicates
            int i = mid;
            while (i >= 0 && arr[i] == match) {
                i--;
            }
            i++; // correct position

            //ab yahan se mtlb 4 se wo agay move kryga aur saray right side walay duplicates ko print kryga
            while (i < 10 && arr[i] == match) {
                cout << i << " ";
                i++;
            }
            break;
        }

        else if (match < arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    if (!found)
        cout << "Number not found!";
}