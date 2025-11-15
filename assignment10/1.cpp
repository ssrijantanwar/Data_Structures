#include <iostream>
using namespace std;

int main() {
    int nums[] = {1,2,3,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    bool found = false;
    for (int i = 0; i < n && !found; ++i)
        for (int j = i+1; j < n; ++j)
            if (nums[i] == nums[j]) { found = true; break; }
    cout << (found ? "true" : "false");
}

