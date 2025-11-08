#include <iostream>
using namespace std;

struct Node{ int data; Node* left; Node* right; };

bool isBST(Node* r,int min,int max){
    if(r==NULL) return true;
    if(r->data<=min || r->data>=max) return false;
    return isBST(r->left,min,r->data) && isBST(r->right,r->data,max);
}

