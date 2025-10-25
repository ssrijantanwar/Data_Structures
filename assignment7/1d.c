#include <iostream>
using namespace std;

void mergeArr(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int b[100];
    while(i<=m && j<=r){
        if(a[i]<a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=m) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    k=0;
    for(i=l;i<=r;i++) a[i]=b[k++];
}

void mergeSort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int main(){
    int n,a[50];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

