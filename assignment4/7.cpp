#include <bits/stdc++.h>
using namespace std;

int minIndex(queue<int>& q, int limit){
    int n = q.size();
    int minVal = INT_MAX, minIdx = -1;
    for(int i=0;i<n;i++){
        int v = q.front(); q.pop();
        if(i <= limit && v < minVal){ minVal = v; minIdx = i; }
        q.push(v);
    }
    return minIdx;
}

void moveMinToRear(queue<int>& q, int minIdx){
    int n = q.size();
    int minVal = INT_MAX;
    for(int i=0;i<n;i++){
        int v = q.front(); q.pop();
        if(i==minIdx) minVal = v;
        else q.push(v);
    }
    q.push(minVal);
}

void sortQueue(queue<int>& q){
    for(int sorted = 0; sorted < (int)q.size(); ++sorted){
        int limit = (int)q.size() - 1 - sorted;
        int mi = minIndex(q, limit);
        moveMinToRear(q, mi);
    }
}

int main(){
    queue<int> q; int x; while(cin>>x) q.push(x);
    sortQueue(q);
    while(!q.empty()){ cout<<q.front()<< (q.size()>1?' ':'\n'); q.pop(); }
}

