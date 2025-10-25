#include <iostream>
using namespace std;

int part(int a[],int l,int h){
    int p=a[h];
    int i=l-1,t;
    for(int j=l;j<h;j++){
        if(a[j]<p){
            i++;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    t=a[i+1]; a[i+1]=a[h]; a[h]=t;
    return i+1;
}

void quick(int a[],int l,int h){
    if(l<h){
        int pi=part(a,l,h);
        quick(a,l,pi-1);
        quick(a,pi+1,h);
    }
}

int main(){
    int n,a[50];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    quick(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

