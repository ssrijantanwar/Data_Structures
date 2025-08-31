#include <iostream>
using namespace std;
struct Trip{int r,c; long long v;};
int main(){
    int RA,CA,nzA; cin>>RA>>CA>>nzA;
    Trip A[2000]; for(int i=0;i<nzA;i++) cin>>A[i].r>>A[i].c>>A[i].v;
    int RB,CB,nzB; cin>>RB>>CB>>nzB;
    Trip B[2000]; for(int i=0;i<nzB;i++) cin>>B[i].r>>B[i].c>>B[i].v;

    Trip AT[2000]; int nzAT=0;
    for(int i=0;i<nzA;i++){ AT[nzAT].r=A[i].c; AT[nzAT].c=A[i].r; AT[nzAT].v=A[i].v; nzAT++; }
    cout<<CA<<" "<<RA<<" "<<nzAT<<"\n";
    for(int i=0;i<nzAT;i++) cout<<AT[i].r<<" "<<AT[i].c<<" "<<AT[i].v<<"\n";

    Trip C[4000]; int nzC=0;
    for(int i=0;i<nzA;i++){ C[nzC]=A[i]; nzC++; }
    for(int i=0;i<nzB;i++){
        int r=B[i].r,c=B[i].c; long long v=B[i].v; int f=-1;
        for(int j=0;j<nzC;j++) if(C[j].r==r&&C[j].c==c){ f=j; break; }
        if(f==-1){ C[nzC].r=r; C[nzC].c=c; C[nzC].v=v; nzC++; } else C[f].v+=v;
    }
    int nzC2=0; for(int i=0;i<nzC;i++) if(C[i].v!=0) C[nzC2++]=C[i];
    cout<<RA<<" "<<CA<<" "<<nzC2<<"\n";
    for(int i=0;i<nzC2;i++) cout<<C[i].r<<" "<<C[i].c<<" "<<C[i].v<<"\n";

    Trip D[4000]; int nzD=0;
    for(int i=0;i<nzA;i++){
        for(int j=0;j<nzB;j++){
            if(A[i].c==B[j].r){
                int r=A[i].r, c=B[j].c; long long val=A[i].v*B[j].v;
                int f=-1; for(int t=0;t<nzD;t++) if(D[t].r==r&&D[t].c==c){ f=t; break; }
                if(f==-1){ D[nzD].r=r; D[nzD].c=c; D[nzD].v=val; nzD++; } else D[f].v+=val;
            }
        }
    }
    int nzD2=0; for(int i=0;i<nzD;i++) if(D[i].v!=0) D[nzD2++]=D[i];
    cout<<RA<<" "<<CB<<" "<<nzD2<<"\n";
    for(int i=0;i<nzD2;i++) cout<<D[i].r<<" "<<D[i].c<<" "<<D[i].v<<"\n";
    return 0;
}

