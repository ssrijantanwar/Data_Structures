#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    long long a[2000]; for(int i=0;i<n;i++) cin>>a[i];
    long long cnt=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(a[i]>a[j]) cnt++;
    cout<<cnt<<"\n";
    return 0;
}

