#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) return -1;
        Node* temp = top;
        top = top->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) return -1;
        Node* temp = front;
        front = front->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    Stack stack;
    Queue queue;
    int val;

    for (int i = 0; i < n; ++i) {
        cin >> val;
        stack.push(val);
    }

    for (int i = 0; i < m; ++i) {
        cin >> val;
        queue.enqueue(val);
    }

    bool isSame = true;
    for (int i = 0; i < n; ++i) {
        int stackTop = stack.pop();
        int queueFront = queue.dequeue();

        if (stackTop != queueFront) {
            isSame = false;
            break;
        }
    }

    if (isSame) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
