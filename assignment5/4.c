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

void reverseList(){
    Node* p=NULL; Node* c=head; Node* next;
    while(c!=NULL){
        next=c->next; c->next=p; p=c; c=next;
    }
    head=p;
}

void display(){
    Node* t=head;
    while(t!=NULL){ cout<<t->data<<" "; t=t->next; }
    cout<<endl;
}

int main(){
    insert(1); insert(2); insert(3); insert(4);
    reverseList();
    display();
}

