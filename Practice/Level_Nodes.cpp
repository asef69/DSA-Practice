#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    if(val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        f->left = myLeft;
        f->right = myRight;
        if(myLeft) q.push(myLeft);
        if(myRight) q.push(myRight);
    }
    return root;
}

void printLevelNodes(Node* root, int level) {
    if (!root) {
        cout << "Invalid" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    int currentLevel = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> nodesAtLevel;

        for (int i = 0; i < levelSize; i++) {
            Node* currentNode = q.front();
            q.pop();
            nodesAtLevel.push_back(currentNode->val);

            if (currentNode->left) q.push(currentNode->left);
            if (currentNode->right) q.push(currentNode->right);
        }

        if (currentLevel == level) {
            for (int i = 0; i < nodesAtLevel.size(); i++) {
                cout << nodesAtLevel[i] << (i == nodesAtLevel.size() - 1 ? "" : " ");
            }
            cout << endl;
            return;
        }

        currentLevel++;
    }

    cout << "Invalid" << endl;
}

int main() {
    Node* root = input_tree();
    int x; 
    cin >> x;
    printLevelNodes(root, x);
}
