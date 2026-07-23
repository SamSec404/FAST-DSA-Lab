#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;   // empty cell
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing: (h + i^2) % size
        while (table[(index + i * i) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        int newIndex = (index + i * i) % size;
        table[newIndex] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main() {
    HashTable h(10);

    h.insertKey(12);
    h.insertKey(22);
    h.insertKey(32);
    h.insertKey(42);
    h.insertKey(52);

    h.display();
}
