#include <bits/stdc++.h>
using namespace std;

struct SimpleQueue {
    int n, front, rear;
    vector<int> a;
    SimpleQueue(int cap): n(cap), front(0), rear(-1), a(cap) {}
    bool isEmpty() const { return front > rear; }
    bool isFull()  const { return rear == n - 1; }
    bool enqueue(int x){ if(isFull()) return false; a[++rear] = x; return true; }
    bool dequeue(int &out){ if(isEmpty()) return false; out = a[front++]; return true; }
    bool peek(int &out) const { if(isEmpty()) return false; out = a[front]; return true; }
    void display() const {
        if(isEmpty()){ cout << "Queue is empty\n"; return; }
        for(int i=front;i<=rear;i++) cout << a[i] << (i<rear?' ':'\n');
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int cap; cout << "Capacity? "; if(!(cin>>cap)) return 0;
    SimpleQueue q(cap);
    while(true){
        cout << "\n1.Enqueue  2.Dequeue  3.isEmpty  4.isFull  5.Display  6.Peek  0.Exit\nChoice: ";
        int ch; if(!(cin>>ch)) break;
        if(ch==0) break;
        if(ch==1){ int x; cin>>x; cout<<(q.enqueue(x)?"Enqueued\n":"Full\n"); }
        else if(ch==2){ int v; cout<<(q.dequeue(v)?("Dequeued: "+to_string(v)+"\n"):"Empty\n"); }
        else if(ch==3){ cout << (q.isEmpty()?"true\n":"false\n"); }
        else if(ch==4){ cout << (q.isFull() ?"true\n":"false\n"); }
        else if(ch==5){ q.display(); }
        else if(ch==6){ int v; cout<<(q.peek(v)?("Front: "+to_string(v)+"\n"):"Empty\n"); }
        else cout<<"Invalid\n";
    }
}

