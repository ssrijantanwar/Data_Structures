#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    long long a[5000]; for(int i=0;i<n;i++) cin>>a[i];
    int distinct=0;
    for(int i=0;i<n;i++){
        bool seen=false;
        for(int j=0;j<i;j++) if(a[j]==a[i]){ seen=true; break; }
        if(!seen) distinct++;
    }
    cout<<distinct<<"\n";
    return 0;
}

