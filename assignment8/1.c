#include <iostream>
using namespace std;

struct Node{ int data; Node* left; Node* right; };
Node* root=NULL;

Node* create(){
    int x;
    cin>>x;
    if(x==-1) return NULL;
    Node* n=new Node();
    n->data=x;
    n->left=create();
    n->right=create();
    return n;
}

void preorder(Node* r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r){
    if(r==NULL) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node* r){
    if(r==NULL) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main(){
    root=create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
}

