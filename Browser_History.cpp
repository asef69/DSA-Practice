#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string address;
    Node* prev;
    Node* next;

    Node(string addr) : address(addr), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addAddress(const string& address) {
        Node* newNode = new Node(address);

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* findNode(const string& address) {
        Node* temp = head;
        while (temp) {
            if (temp->address == address) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void visit(const string& address) {
        Node* node = findNode(address);
        if (node != nullptr) {
            current = node;
            cout << current->address << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void next() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            cout << current->address << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void prev() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            cout << current->address << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    vector<string> addresses;
    string address;

    while (cin >> address && address != "end") {
        addresses.push_back(address);
    }

    DoublyLinkedList list;
    for (const string& addr : addresses) {
        list.addAddress(addr);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string command, param;
        cin >> command;

        if (command == "visit") {
            cin >> param;
            list.visit(param);
        } else if (command == "next") {
            list.next();
        } else if (command == "prev") {
            list.prev();
        }
    }

    return 0;
}
