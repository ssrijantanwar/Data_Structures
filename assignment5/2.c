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

int deleteOcc(int k){
    int c=0;
    while(head!=NULL && head->data==k){
        Node* t=head; head=head->next; delete t; c++;
    }
    Node* t=head;
    while(t!=NULL && t->next!=NULL){
        if(t->next->data==k){
            Node* d=t->next; t->next=t->next->next; delete d; c++;
        } else t=t->next;
    }
    return c;
}

void display(){
    Node* t=head;
    while(t!=NULL){ cout<<t->data<<" "; t=t->next; }
    cout<<endl;
}

int main(){
    insert(1); insert(2); insert(1); insert(2); insert(1); insert(3); insert(1);
    int key=1;
    int c=deleteOcc(key);
    cout<<"Count: "<<c<<endl;
    display();
}

