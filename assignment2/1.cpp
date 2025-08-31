#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int a[1000]; for(int i=0;i<n;i++) cin>>a[i];
    int x; cin>>x;
    int lin=-1; for(int i=0;i<n;i++){ if(a[i]==x){ lin=i; break; } }
    cout<<lin<<"\n";
    int l=0,r=n-1,bin=-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==x){ bin=m; break; }
        if(a[m]<x) l=m+1; else r=m-1;
    }
    cout<<bin<<"\n";
    return 0;
}

