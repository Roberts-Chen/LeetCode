#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool exist(TreeNode *root, int level, int k) {
    int bits = 1 << (level - 1);
    while (root != NULL && bits > 0) {
        if (bits & k) {
            root = root->right;
        } else {
            root = root->left;
        }
        bits >>= 1;
    }
    return root != NULL;
}

int countNodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    TreeNode *p = root;
    int level = 0;
    while (p->left != NULL) {
        ++level;
        p = p->left;
    }

    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high) {
        int mid = (high - low + 1) / 2 + low;
        if (exist(root, level, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int k = 16;
    k >>= 1;
    k >>= 1;
    k >>= 1;
    k >>= 1;
    cout << k << endl;
    return 0;
}

