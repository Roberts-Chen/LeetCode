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
        unordered_map<int, int> paths;
        // 加上这一句，作用有二
        // 1) 若sum为0，则什么都不选，这样的路径只有一条
        // 2) 若搜索到某个节点后路径和等于sum，那么res += preSum[sum - sum]，这里也是需要preSum[0] = 1的
        paths[0] = 1;
        return helper(root, sum, 0, paths);
    }

    int helper(TreeNode *root, int sum, int pathSum, unordered_map<int, int> &paths) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        pathSum += root->val;
        if (paths.count(pathSum - sum)) {
            res += paths[pathSum - sum];
        }

        if (paths.count(pathSum)) {
            paths[pathSum]++;
        } else {
            paths[pathSum] = 1;
        }

        res = helper(root->left, sum, pathSum, paths) + helper(root->right, sum, pathSum, paths) + res;
        paths[pathSum]--;
        return res;
    }
};

int main() {
    return 0;
}
