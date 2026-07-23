#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

class HashTable {
private:
    Node** table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    int hashFunction(int key) {
        return key % size;
    }

    // Insert in sorted order inside the chain
    void insertKey(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        // If bucket empty OR new key is smallest → insert at start
        if (table[index] == nullptr || table[index]->key >= key) {
            newNode->next = table[index];
            table[index] = newNode;
            return;
        }

        // Otherwise find sorted position
        Node* current = table[index];
        while (current->next != nullptr && current->next->key < key) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " -> ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable h(10);

    // Insert in random order
    h.insertKey(25);
    h.insertKey(15);
    h.insertKey(35);
    h.insertKey(5);
    h.insertKey(45);
    h.insertKey(12);
    h.insertKey(22);

    h.display();
}
