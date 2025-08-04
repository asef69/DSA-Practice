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

bool areIdentical(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->val != head2->val) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
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
     Node* head1= NULL;
    Node* tail1= NULL;
    int val1;
    while(true) {
        cin >> val1;
        if(val1== -1) {
            break;
        }
        insert_at_tail(head1,val1,tail1);
    }

  if (areIdentical(head, head1)) {
    cout << "YES"<<endl;
} else {
    cout << "NO"<<endl;
}
    return 0;
}


