#include <iostream>
using namespace std;

struct Node{ int data; Node* next; };
Node* head=NULL;

void insert(int x){
    Node* n=new Node(); n->data=x; n->next=NULL;
    if(head==NULL){ head=n; n->next=n; return; }
    Node* t=head;
    while(t->next!=head) t=t->next;
    t->next=n; n->next=head;
}
void insertBeg(int x){
    Node* n=new Node(); n->data=x;
    if(head==NULL){ head=n; n->next=n; return; }
    Node* t=head;
    while(t->next!=head) t=t->next;
    n->next=head; t->next=n; head=n;
}
void insertBeforeAfter(int x,int k,bool before){
    Node* n=new Node(); n->data=x;
    if(head==NULL) return;
    Node* t=head; Node* p=NULL;
    do{ if(t->data==k) break; p=t; t=t->next; }while(t!=head);
    if(t->data!=k) return;
    if(before){
        if(t==head){
            insertBeg(x); return;
        }
        n->next=t; p->next=n;
    } else {
        n->next=t->next; t->next=n;
    }
}
void deleteNode(int k){
    if(head==NULL) return;
    Node* t=head; Node* p=NULL;
    do{ if(t->data==k) break; p=t; t=t->next; }while(t!=head);
    if(t->data!=k) return;
    if(t==head && t->next==head){ delete head; head=NULL; return; }
    if(t==head){
        while(p->next!=head) p=p->next;
        head=head->next; p->next=head; delete t; return;
    }
    p->next=t->next; delete t;
}
int search(int k){
    if(head==NULL) return -1;
    Node* t=head; int pos=1;
    do{ if(t->data==k) return pos; t=t->next; pos++; }while(t!=head);
    return -1;
}
void display(){
    if(head==NULL) return;
    Node* t=head;
    do{ cout<<t->data<<" "; t=t->next; }while(t!=head);
    cout<<endl;
}

int main(){
    int ch,x,k;
    while(1){
        cout<<"\n1.InBeg 2.InEnd 3.InBefore 4.InAfter 5.Delete 6.Search 7.Display 8.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: cin>>x; insertBeg(x); break;
            case 2: cin>>x; insert(x); break;
            case 3: cin>>x>>k; insertBeforeAfter(x,k,true); break;
            case 4: cin>>x>>k; insertBeforeAfter(x,k,false); break;
            case 5: cin>>k; deleteNode(k); break;
            case 6: cin>>k; cout<<search(k)<<endl; break;
            case 7: display(); break;
            case 8: return 0;
        }
    }
}

