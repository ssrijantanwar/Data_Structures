#include <iostream>
using namespace std;
int main(){
    char c; cin>>c;
    if(c>='A'&&c<='Z') c=char(c-'A'+'a');
    cout<<c<<"\n";
    return 0;
}

