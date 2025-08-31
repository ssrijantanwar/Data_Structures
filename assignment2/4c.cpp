#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; getline(cin,s);
    for(char c: s){
        char x=c; if(x>='A'&&x<='Z') x=char(x-'A'+'a');
        if(x!='a'&&x!='e'&&x!='i'&&x!='o'&&x!='u') cout<<c;
    }
    cout<<"\n";
    return 0;
}

