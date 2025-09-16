#include <bits/stdc++.h>
using namespace std;

struct Stack2Q {
    queue<int> q1, q2;
    void push(int x){ q1.push(x); }
    int pop(){
        if(q1.empty()) throw runtime_error("empty");
        while(q1.size()>1){ q2.push(q1.front()); q1.pop(); }
        int topv = q1.front(); q1.pop();
        swap(q1,q2);
        return topv;
    }
    int top(){
        if(q1.empty()) throw runtime_error("empty");
        while(q1.size()>1){ q2.push(q1.front()); q1.pop(); }
        int topv = q1.front();
        q2.push(topv); q1.pop();
        swap(q1,q2);
        return topv;
    }
    bool empty() const { return q1.empty(); }
};

struct Stack1Q {
    queue<int> q;
    void push(int x){
        int sz = q.size();
        q.push(x);
        while(sz--){ q.push(q.front()); q.pop(); }
    }
    int pop(){
        if(q.empty()) throw runtime_error("empty");
        int v = q.front(); q.pop(); return v;
    }
    int top(){
        if(q.empty()) throw runtime_error("empty");
        return q.front();
    }
    bool empty() const { return q.empty(); }
};

int main(){
    Stack2Q s2; s2.push(10); s2.push(20); cout<<s2.top()<<" "; cout<<s2.pop()<<"\n";
    Stack1Q s1; s1.push(5); s1.push(7); cout<<s1.top()<<" "; cout<<s1.pop()<<"\n";
}

