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
        this->right=NULL;
    }
};
Node* input_tree(){
    int val;
    cin >> val;
    if(val == -1) return NULL;
    else{
        Node* root=new Node(val);
        queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()){
            Node* f=q.front();
            q.pop();
            int l,r;cin>>l>>r;
            Node* myLeft,*myRight;
            if(l==-1) myLeft=NULL;
            else{
                myLeft=new Node(l);
            }
            if(r==-1) myRight=NULL;
            else{
                myRight=new Node(r);
            }
            f->left=myLeft;
            f->right=myRight;
            if(myLeft) q.push(myLeft);
            if(myRight) q.push(myRight);

        }
        return root;
    }
}
int count_node(Node* root){
    if(root==NULL) return 0;
    return 1+count_node(root->left)+count_node(root->right);
}
int depth(Node* root){
    if(root==NULL) return 0;
    return 1+max(depth(root->left),depth(root->right));
}
int main(){
    Node* root=input_tree();
    int n=count_node(root);
    int d=depth(root);
    if(n==pow(2,d)-1) cout<<"YES";
    else cout<<"NO";
}