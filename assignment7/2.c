#include <iostream>
using namespace std;

int main(){
    int a[50],n,i,j,min,max,t;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];

    for(i=0;i<n/2;i++){
        min=i;
        max=n-i-1;
        for(j=i;j<n-i;j++){
            if(a[j]<a[min]) min=j;
            if(a[j]>a[max]) max=j;
        }
        t=a[i]; a[i]=a[min]; a[min]=t;

        if(max==i) max=min;

        t=a[n-i-1]; a[n-i-1]=a[max]; a[max]=t;
    }

    for(i=0;i<n;i++) cout<<a[i]<<" ";
}

