#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node* prev; };
Node* head=NULL;

void insertBeg(int x){
    Node* n=new Node(); n->data=x; n->next=head; n->prev=NULL;
    if(head!=NULL) head->prev=n;
    head=n;
}
void insertEnd(int x){
    Node* n=new Node(); n->data=x; n->next=NULL;
    if(head==NULL){ n->prev=NULL; head=n; return; }
    Node* t=head; while(t->next!=NULL) t=t->next;
    t->next=n; n->prev=t;
}
void insertBeforeAfter(int x,int k,bool before){
    Node* n=new Node(); n->data=x;
    Node* t=head;
    while(t!=NULL && t->data!=k) t=t->next;
    if(t==NULL) return;

    if(before){
        if(t==head){ insertBeg(x); return; }
        n->next=t; n->prev=t->prev; t->prev->next=n; t->prev=n;
    } else {
        n->next=t->next; n->prev=t;
        if(t->next!=NULL) t->next->prev=n;
        t->next=n;
    }
}
void deleteNode(int k){
    Node* t=head;
    while(t!=NULL && t->data!=k) t=t->next;
    if(t==NULL) return;
    if(t==head){ head=head->next; if(head) head->prev=NULL; delete t; return; }
    if(t->next!=NULL) t->next->prev=t->prev;
    t->prev->next=t->next; delete t;
}
int search(int k){
    Node* t=head; int p=1;
    while(t!=NULL){ if(t->data==k) return p; p++; t=t->next; }
    return -1;
}
void display(){
    Node* t=head; while(t!=NULL){ cout<<t->data<<" "; t=t->next; } cout<<endl;
}

int main(){
    int ch,x,k;
    while(1){
        cout<<"\n1.InBeg 2.InEnd 3.InBefore 4.InAfter 5.Delete 6.Search 7.Display 8.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: cin>>x; insertBeg(x); break;
            case 2: cin>>x; insertEnd(x); break;
            case 3: cin>>x>>k; insertBeforeAfter(x,k,true); break;
            case 4: cin>>x>>k; insertBeforeAfter(x,k,false); break;
            case 5: cin>>k; deleteNode(k); break;
            case 6: cin>>k; cout<<search(k)<<endl; break;
            case 7: display(); break;
            case 8: return 0;
        }
    }
}

