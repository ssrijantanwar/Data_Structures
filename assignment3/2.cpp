#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "DataStructure";
    stack<char> s;

    for (char c : str) s.push(c);

    cout << "Reversed string: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}

