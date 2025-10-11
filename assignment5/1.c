#include <iostream>
using namespace std;

struct Node{ int data; Node* next; };
Node* head=NULL;

void insertBeg(int x){
    Node* n=new Node(); n->data=x; n->next=head; head=n;
}
void insertEnd(int x){
    Node* n=new Node(); n->data=x; n->next=NULL;
    if(head==NULL){ head=n; return; }
    Node* t=head; while(t->next!=NULL) t=t->next; t->next=n;
}
void insertBeforeAfter(int x,int k,bool before){
    Node* n=new Node(); n->data=x;
    if(head==NULL) return;
    if(before && head->data==k){ n->next=head; head=n; return; }
    Node* t=head;
    while(t->next!=NULL && t->next->data!=k) t=t->next;
    if(t->next==NULL) return;
    if(before){ n->next=t->next; t->next=n; }
    else{ Node* nxt=t->next->next; t->next->next=n; n->next=nxt; }
}
void delBeg(){
    if(head==NULL) return;
    Node* t=head; head=head->next; delete t;
}
void delEnd(){
    if(head==NULL) return;
    if(head->next==NULL){ delete head; head=NULL; return; }
    Node* t=head; while(t->next->next!=NULL) t=t->next;
    delete t->next; t->next=NULL;
}
void delNode(int k){
    if(head==NULL) return;
    if(head->data==k){ Node* t=head; head=head->next; delete t; return; }
    Node* t=head; while(t->next!=NULL && t->next->data!=k) t=t->next;
    if(t->next==NULL) return;
    Node* d=t->next; t->next=t->next->next; delete d;
}
int search(int k){
    Node* t=head; int p=1;
    while(t!=NULL){ if(t->data==k) return p; t=t->next; p++; }
    return -1;
}
void display(){
    Node* t=head; while(t!=NULL){ cout<<t->data<<" "; t=t->next; }
    cout<<endl;
}

int main(){
    int ch,x,k;
    while(1){
        cout<<"\n1.InBeg 2.InEnd 3.InBefore 4.InAfter 5.DelBeg 6.DelEnd 7.DelNode 8.Search 9.Display 10.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: cin>>x; insertBeg(x); break;
            case 2: cin>>x; insertEnd(x); break;
            case 3: cin>>x>>k; insertBeforeAfter(x,k,true); break;
            case 4: cin>>x>>k; insertBeforeAfter(x,k,false); break;
            case 5: delBeg(); break;
            case 6: delEnd(); break;
            case 7: cin>>k; delNode(k); break;
            case 8: cin>>k; cout<<search(k)<<endl; break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}

