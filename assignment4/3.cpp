#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int>& q){
    int n = (int)q.size();
    if(n%2){ cerr<<"Queue size must be even.\n"; return; }
    stack<int> s;
    int half = n/2;
    for(int i=0;i<half;i++){ s.push(q.front()); q.pop(); }
    while(!s.empty()){ q.push(s.top()); s.pop(); }
    for(int i=0;i<half;i++){ q.push(q.front()); q.pop(); }
    for(int i=0;i<half;i++){ s.push(q.front()); q.pop(); }
    while(!s.empty()){
        q.push(s.top()); s.pop();
        q.push(q.front()); q.pop();
    }
}

int main(){
    queue<int> q; int x; 
    while(cin>>x) q.push(x);
    if(q.empty()){ cout<<"(empty)\n"; return 0; }
    interleave(q);
    while(!q.empty()){ cout<<q.front()<< (q.size()>1?' ':'\n'); q.pop(); }
}

