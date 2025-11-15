#include <iostream>
using namespace std;

int main() {
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int nA = sizeof(A)/sizeof(A[0]);
    int nB = sizeof(B)/sizeof(B[0]);

    int out[100], outCount = 0;
    for (int i = 0; i < nA; ++i) {
        for (int j = 0; j < nB; ++j) {
            if (A[i] == B[j]) {
                bool already = false;
                for (int k = 0; k < outCount; ++k) if (out[k] == A[i]) { already = true; break; }
                if (!already) out[outCount++] = A[i];
            }
        }
    }
    for (int i = 0; i < outCount; ++i) {
        if (i) cout << ", ";
        cout << out[i];
    }
}

