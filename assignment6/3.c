#include <iostream>
using namespace std;

struct Node{ int data; Node* next; };
Node* head=NULL;

void insert(int x){
    Node* n=new Node(); n->data=x; n->next=NULL;
    if(head==NULL){ head=n; n->next=n; return; }
    Node* t=head; while(t->next!=head) t=t->next;
    t->next=n; n->next=head;
}
void display(){
    if(head==NULL) return;
    Node* t=head;
    do{ cout<<t->data<<" "; t=t->next; }while(t!=head);
    cout<<head->data;
}

int main(){
    insert(20); insert(100); insert(40); insert(80); insert(60);
    display();
}

