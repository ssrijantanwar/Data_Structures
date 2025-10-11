#include <iostream>
using namespace std;

struct Node{ int data; Node* next; };
Node* head=NULL;

void insert(int x){
    Node* n=new Node();
    n->data=x; n->next=NULL;
    if(head==NULL){ head=n; return; }
    Node* t=head; while(t->next!=NULL) t=t->next; t->next=n;
}

int findMid(){
    Node* s=head; Node* f=head;
    while(f!=NULL && f->next!=NULL){
        s=s->next; f=f->next->next;
    }
    return s->data;
}

int main(){
    insert(1); insert(2); insert(3); insert(4); insert(5);
    cout<<findMid();
}

