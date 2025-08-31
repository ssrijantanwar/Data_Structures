#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int a[1000]; for(int i=0;i<n-1;i++) cin>>a[i];
    long long s=1LL*n*(n+1)/2, s2=0; for(int i=0;i<n-1;i++) s2+=a[i];
    cout<<s-s2<<"\n";
    int l=0,r=n-2,ans=n;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==m+1) l=m+1; else { ans=m+1; r=m-1; }
    }
    cout<<ans<<"\n";
    return 0;
}

