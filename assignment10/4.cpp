#include <iostream>
using namespace std;

int main() {
    int arr[] = {4,5,1,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) if (arr[j] == arr[i]) ++cnt;
        if (cnt == 1) { ans = arr[i]; break; }
    }
    if (ans == -1) cout << "None";
    else cout << ans;
}

