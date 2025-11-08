#include <iostream>
using namespace std;

int h[50],n=0;

void insertPQ(int x){
    h[n]=x;
    int i=n;
    while(i>0 && h[i]>h[(i-1)/2]){
        int t=h[i]; h[i]=h[(i-1)/2]; h[(i-1)/2]=t;
        i=(i-1)/2;
    }
    n++;
}

int deletePQ(){
    int r=h[0];
    h[0]=h[n-1];
    n--;
    int i=0,l,rgt,largest,t;
    while(1){
        l=2*i+1; rgt=2*i+2; largest=i;
        if(l<n && h[l]>h[largest]) largest=l;
        if(rgt<n && h[rgt]>h[largest]) largest=rgt;
        if(largest==i) break;
        t=h[i]; h[i]=h[largest]; h[largest]=t;
        i=largest;
    }
    return r;
}

int main(){
    insertPQ(40);
    insertPQ(10);
    insertPQ(60);
    insertPQ(30);
    cout<<deletePQ()<<endl;
    cout<<deletePQ()<<endl;
}

