#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    long long lo[1000]={0}, di[1000]={0}, up[1000]={0};
    int k; cin>>k;
    for(int t=0;t<k;t++){
        int i,j; long long v; cin>>i>>j>>v;
        if(i==j) di[i]=v; else if(i==j+1) lo[j]=v; else if(j==i+1) up[i]=v;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long x=0;
            if(i==j) x=di[i]; else if(i==j+1) x=lo[j]; else if(j==i+1) x=up[i];
            cout<<x<<(j<n-1?" ":"\n");
        }
    }
    return 0;
}

