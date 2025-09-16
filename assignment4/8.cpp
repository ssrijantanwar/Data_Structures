#include <bits/stdc++.h>
using namespace std;

bool canSortIntoIncreasing(queue<int> q){
    int n = q.size();
    int need = 1;
    stack<int> st;
    while(!q.empty()){
        if(q.front()==need){ q.pop(); need++; }
        else if(!st.empty() && st.top()==need){ st.pop(); need++; }
        else { st.push(q.front()); q.pop(); }
    }
    while(!st.empty() && st.top()==need){ st.pop(); need++; }
    return need==n+1;
}

int main(){
    queue<int> q; int x; while(cin>>x) q.push(x);
    cout << (canSortIntoIncreasing(q) ? "Yes\n":"No\n");
}

