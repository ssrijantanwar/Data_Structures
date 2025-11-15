#include <iostream>
using namespace std;

int main() {
    int nums[] = {2,3,2,4,3,2};
    int n = sizeof(nums)/sizeof(nums[0]);

    int vals[100], cnt[100], m = 0;
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        int idx = -1;
        for (int j = 0; j < m; ++j) if (vals[j] == x) { idx = j; break; }
        if (idx == -1) { vals[m] = x; cnt[m] = 1; ++m; }
        else cnt[idx] += 1;
    }
    for (int i = 0; i < m; ++i) {
        cout << "• " << vals[i] << " → " << cnt[i] << (cnt[i] == 1 ? " time\n" : " times\n");
    }
}

