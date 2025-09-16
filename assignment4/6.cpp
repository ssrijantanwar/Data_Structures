#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n) || n<=0) return 0;
    queue<string> q; q.push("1");
    for(int i=1;i<=n;i++){
        string s = q.front(); q.pop();
        cout << s << (i<n? ' ' : '\n');
        q.push(s + "0");
        q.push(s + "1");
    }
}

