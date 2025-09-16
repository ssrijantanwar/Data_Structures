#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    queue<char> q;
    vector<int> freq(256,0);
    string token;
    while (cin >> token){
        for(char ch: token){
            if(isspace((unsigned char)ch)) continue;
            freq[(unsigned char)ch]++;
            q.push(ch);
            while(!q.empty() && freq[(unsigned char)q.front()]>1) q.pop();
            if(q.empty()) cout << -1 << ' ';
            else          cout << q.front() << ' ';
        }
    }
    cout << '\n';
    return 0;
}

