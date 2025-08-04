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
vector<int> descending_leaf(Node* root){
    if(root==NULL){
        vector<int> v;
        return v;
    }
    if(root->left==NULL && root->right==NULL){
        vector<int> v;
        v.push_back(root->val);
        return v;
    }
    vector<int> left=descending_leaf(root->left);
    vector<int> right=descending_leaf(root->right);
    vector<int> ans;
    for(int i=0;i<left.size();i++){
        ans.push_back(left[i]);
    }
    for(int i=0;i<right.size();i++){
        ans.push_back(right[i]);
    }
    //vector<int> res;
    sort(ans.begin(),ans.end());
    //reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    Node* root=input_tree();
    vector<int> ans=descending_leaf(root);
    while(ans.size()){
        cout<<ans.back()<<" ";
        ans.pop_back();
    }
}