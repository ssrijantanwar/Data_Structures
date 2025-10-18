#include <iostream>
using namespace std;

struct Node{ char data; Node* next; Node* prev; };
Node* head=NULL;

void insert(char x){
    Node* n=new Node(); n->data=x; n->next=NULL;
    if(head==NULL){ head=n; n->prev=NULL; return; }
    Node* t=head; while(t->next!=NULL) t=t->next;
    t->next=n; n->prev=t;
}
bool palindrome(){
    Node* l=head; Node* r=head;
    while(r->next!=NULL) r=r->next;
    while(l!=r && r->next!=l){
        if(l->data!=r->data) return false;
        l=l->next; r=r->prev;
    }
    return true;
}

int main(){
    insert('m'); insert('a'); insert('d'); insert('a'); insert('m');
    if(palindrome()) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}

