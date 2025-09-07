#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_any_pos(Node* &head, Node* &tail, int val, int idx, int &size) {
   
    if (idx == 0) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode; 
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
        size++;
        return;
    }

   
    if (idx == size) {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = tail = newNode; 
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; 
        }
        size++;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;

    size++;
}

void print_forward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_backward(Node* tail) {
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->prev != NULL) cout << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val, idx, n, size = 0;
    cin >> n;
    
    while (n--) {
        cin >> idx >> val;
        if (idx < 0 || idx > size) {
            cout << "Invalid" << endl;
        } else {
            insert_at_any_pos(head, tail, val, idx, size);
            cout << "L -> ";
            print_forward(head);
            cout << "R -> ";
            print_backward(tail);
        }
    }
    return 0;
}
