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
            table[i] = -1;   // -1 means empty
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertKey(int key) {
        int index = hashFunction(key);

        // linear probing
        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " -> " << table[i] << endl;
        }
    }
};

int main() {
    HashTable h(10);

    h.insertKey(12);
    h.insertKey(22);
    h.insertKey(32);
    h.insertKey(15);

    h.display();
}
