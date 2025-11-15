#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(0), right(0) {}
};

void collect(TreeNode* node, int arr[], int &idx) {
    if (!node) return;
    arr[idx++] = node->val;
    collect(node->left, arr, idx);
    collect(node->right, arr, idx);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    int arr[100], n = 0;
    collect(root, arr, n);

    bool dup = false;
    for (int i = 0; i < n && !dup; ++i)
        for (int j = i+1; j < n; ++j)
            if (arr[i] == arr[j]) { dup = true; break; }

    if (dup) cout << "Duplicates Found";
    else cout << "No Duplicates";
}

