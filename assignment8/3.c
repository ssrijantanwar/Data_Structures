#include <iostream>
using namespace std;

struct Node{ int data; Node* left; Node* right; };
Node* root=NULL;

Node* insert(Node* r,int x){
    if(r==NULL){ r=new Node(); r->data=x; r->left=r->right=NULL; return r; }
    if(x<r->data) r->left=insert(r->left,x);
    else if(x>r->data) r->right=insert(r->right,x);
    return r;
}

Node* minNode(Node* r){
    while(r->left!=NULL) r=r->left;
    return r;
}

Node* remove(Node* r,int x){
    if(r==NULL) return r;
    if(x<r->data) r->left=remove(r->left,x);
    else if(x>r->data) r->right=remove(r->right,x);
    else{
        if(r->left==NULL){ Node* t=r->right; delete r; return t; }
        else if(r->right==NULL){ Node* t=r->left; delete r; return t; }
        Node* t=minNode(r->right);
        r->data=t->data;
        r->right=remove(r->right,t->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(r==NULL) return 0;
    int l=maxDepth(r->left);
    int rt=maxDepth(r->right);
    return (l>rt?l:rt)+1;
}

int minDepth(Node* r){
    if(r==NULL) return 0;
    int l=minDepth(r->left);
    int rt=minDepth(r->right);
    return (l<rt?l:rt)+1;
}

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>x; root=insert(root,x); }
    int d; cin>>d;
    root=remove(root,d);
    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
}

