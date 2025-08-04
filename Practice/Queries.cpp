#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int value)
    {
        this->val = value;
        this->next = NULL;
    }
};

void insertAtHead(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtIndex(ListNode *&head, int index)
{
    if (!head)
        return;
    if (index == 0)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode *temp = head;
    for (int i = 0; temp != nullptr && i < index - 1; ++i)
    {
        temp = temp->next;
    }

    if (!temp || !temp->next)
    {
        return;
    }

    ListNode *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void printList(ListNode *head)
{
    if (!head)
    {
        cout << endl;
        return;
    }

    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val;
        if (temp->next)
            cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int Q;
    cin >> Q;

    ListNode *head = nullptr;
    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (X == 0)
        {

            insertAtHead(head, V);
        }
        else if (X == 1)
        {

            insertAtTail(head, V);
        }
        else if (X == 2)
        {

            deleteAtIndex(head, V);
        }

        printList(head);
    }

    return 0;
}
