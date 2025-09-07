#include <bits/stdc++.h>
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
    if (val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            current->left = new Node(left);
            q.push(current->left);
        }
        if (right != -1) {
            current->right = new Node(right);
            q.push(current->right);
        }
    }
    return root;
}
void outerLeft(Node* root) {
  if(root==NULL) return;
    if(root->left) outerLeft(root->left);
    if(root->right && !root->left) outerLeft(root->right);
    cout<<root->val<<" ";
}
void outerRight(Node* root) {
   if(root==NULL) return;
  cout<<root->val<<" ";
    if(root->right) outerRight(root->right);
    if(!root->right && root->left) outerRight(root->left);
}

int main() {
    Node* root = input_tree();
    if (root == NULL) return 0;

    outerLeft(root->left);
    cout << root->val << " ";
    outerRight(root->right);
    return 0;
}
