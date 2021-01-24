//
// Created by 22577 on 2021/1/24.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <limits>

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        return dfs1(root, sum);
    }

    int dfs1(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int x = dfs2(root, 0, targetSum);
        return x + dfs1(root->left, targetSum) + dfs1(root->right, targetSum);
    }

    int dfs2(TreeNode *root, int preSum, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        preSum += root->val;
        if (preSum == targetSum) {
            return 1 + dfs2(root->left, preSum, targetSum) + dfs2(root->right, preSum, targetSum);
        } else {
            return dfs2(root->left, preSum, targetSum) + dfs2(root->right, preSum, targetSum);
        }
    }
};

int main() {
    return 0;
}
