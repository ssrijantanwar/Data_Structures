#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches){
    int cnt0 = 0, cnt1 = 0;
    for(int s: students) (s?cnt1:cnt0)++;
    for(int sw: sandwiches){
        if(sw==0){
            if(cnt0==0) break;
            cnt0--;
        }else{
            if(cnt1==0) break;
            cnt1--;
        }
    }
    return cnt0 + cnt1;
}

int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> students(n), sandwiches(n);
    for(int i=0;i<n;i++) cin>>students[i];
    for(int i=0;i<n;i++) cin>>sandwiches[i];
    cout << countStudents(students, sandwiches) << "\n";
}

