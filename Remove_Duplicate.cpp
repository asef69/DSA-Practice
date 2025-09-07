#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, int val, Node* &tail) {
    Node* n = new Node(val);
    if(head == NULL) {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = tail->next;
}

void remove_duplicates(Node* head) {
    if (head == NULL) return;
    vector<int> seen;
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (find(seen.begin(), seen.end(), current->val) != seen.end()) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        } else {
            seen.push_back(current->val);
            prev = current;
        }
        current = prev->next;
    }
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while(true) {
        cin >> val;
        if(val == -1) {
            break;
        }
        insert_at_tail(head, val, tail);
    }

    remove_duplicates(head);
    print_list(head);

    return 0;
}