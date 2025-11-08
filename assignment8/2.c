#include <iostream>
using namespace std;

struct Node{ int data; Node* left; Node* right; };
Node* root=NULL;

Node* insert(Node* r,int x){
    if(r==NULL){
        r=new Node(); r->data=x; r->left=r->right=NULL;
        return r;
    }
    if(x<r->data) r->left=insert(r->left,x);
    else if(x>r->data) r->right=insert(r->right,x);
    return r;
}

Node* searchRec(Node* r,int x){
    if(r==NULL || r->data==x) return r;
    if(x<r->data) return searchRec(r->left,x);
    return searchRec(r->right,x);
}

Node* searchNonRec(int x){
    Node* t=root;
    while(t!=NULL){
        if(t->data==x) return t;
        if(x<t->data) t=t->left;
        else t=t->right;
    }
    return NULL;
}

int maxElement(Node* r){
    while(r->right!=NULL) r=r->right;
    return r->data;
}

int minElement(Node* r){
    while(r->left!=NULL) r=r->left;
    return r->data;
}

Node* inSucc(Node* n){
    n=n->right;
    while(n->left!=NULL) n=n->left;
    return n;
}

Node* inPred(Node* n){
    n=n->left;
    while(n->right!=NULL) n=n->right;
    return n;
}

int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>x; root=insert(root,x); }
    int s; cin>>s;
    Node* t=searchRec(root,s);
    cout<<maxElement(root)<<endl;
    cout<<minElement(root)<<endl;
}

