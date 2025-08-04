#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, int val, Node *&tail)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    tail = tail->next;
}

int search(Node *head, int x)
{
    Node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->val == x)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        while (true)
        {
            cin >> val;
            if (val == -1)
            {
                break;
            }
            insert_at_tail(head, val, tail);
        }
        int x; 
        cin >> x;
        int index = search(head, x);
        if (index != -1)
        {
            cout << index << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}