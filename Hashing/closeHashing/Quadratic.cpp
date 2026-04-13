#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
int hashTable[TABLE_SIZE];

void insert(int number) {
    int startSlot = number % TABLE_SIZE;

    for (int step = 0; step < TABLE_SIZE; step++) {
        int currentSlot = (startSlot + step * step) % TABLE_SIZE;

        if (hashTable[currentSlot] == -1 || hashTable[currentSlot] == -2) {
            hashTable[currentSlot] = number;
            cout << "Quadratically inserted " << number << " at slot " << currentSlot << endl;
            return;
        }
    }
    cout << "Table full, " << number << " insert nahi hua" << endl;
}

void search(int number) {
    int startSlot = number % TABLE_SIZE;

    for (int step = 0; step < TABLE_SIZE; step++) {
        int currentSlot = (startSlot + step * step) % TABLE_SIZE;

        if (hashTable[currentSlot] == -1)
            break;

        if (hashTable[currentSlot] == number) {
            cout << "Found " << number << " at slot " << currentSlot << endl;
            return;
        }
    }
    cout << number << " not found" << endl;
}

void display() {
    for (int slot = 0; slot < TABLE_SIZE; slot++) {
        cout << "Slot " << slot << " : ";
        if (hashTable[slot] == -1)
            cout << "Empty";
        else if (hashTable[slot] == -2)
            cout << "Deleted";
        else
            cout << hashTable[slot];
        cout << endl;
    }
}

int main() {
    for (int slot = 0; slot < TABLE_SIZE; slot++)
        hashTable[slot] = -1;

    insert(5);
    insert(15);
    insert(25);
    display();
    search(15);

    return 0;
}