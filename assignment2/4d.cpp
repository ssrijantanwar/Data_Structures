#include <iostream>
#include <string>
using namespace std;
int main(){
    int m; cin>>m;
    string s[200];
    for(int i=0;i<m;i++) cin>>s[i];
    for(int i=0;i<m-1;i++) for(int j=0;j<m-1-i;j++) if(s[j]>s[j+1]){ string t=s[j]; s[j]=s[j+1]; s[j+1]=t; }
    for(int i=0;i<m;i++) cout<<s[i]<<"\n";
    return 0;
}

