#include <iostream>
using namespace std;

int main(){
    int a[50],n,i,j,min,t;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        t=a[i]; a[i]=a[min]; a[min]=t;
    }

    for(i=0;i<n;i++) cout<<a[i]<<" ";
}

