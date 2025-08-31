#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    long long a[500000]; for(int i=0;i<n*(n+1)/2;i++) a[i]=0;
    int k; cin>>k;
    for(int t=0;t<k;t++){
        int i,j; long long v; cin>>i>>j>>v;
        if(i<j){ int ii=j,jj=i; a[ii*(ii+1)/2+jj]=v; }
        else a[i*(i+1)/2+j]=v;
    }
    for(int i=0;i<n;i++){ for(int j=0;j<n;j++){ int ii=i,jj=j; if(ii<jj){ int x=ii; ii=jj; jj=x; } cout<<a[ii*(ii+1)/2+jj]<<(j<n-1?" ":"\n"); } }
    return 0;
}

