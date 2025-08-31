#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    long long d[1000]; for(int i=0;i<n;i++) d[i]=0;
    int k; cin>>k;
    for(int t=0;t<k;t++){ int i,j; long long v; cin>>i>>j>>v; if(i==j) d[i]=v; }
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++){ cout<<(i==j?d[i]:0); if(j<n-1) cout<<" "; } cout<<"\n"; }
    return 0;
}

