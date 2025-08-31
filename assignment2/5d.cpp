#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    long long a[500000]; for(int i=0;i<n*(n+1)/2;i++) a[i]=0;
    int k; cin>>k;
    for(int t=0;t<k;t++){ int i,j; long long v; cin>>i>>j>>v; if(i<=j) a[j*(j+1)/2+i]=v; }
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++){ long long x=i>j?0:a[j*(j+1)/2+i]; cout<<x<<(j<n-1?" ":"\n"); } }
    return 0;
}

