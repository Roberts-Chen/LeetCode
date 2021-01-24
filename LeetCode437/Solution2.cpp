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
        vector<int> sumlist;
        return dfs(root, sum, sumlist);
    }

    // 每层都利用sumlist记录每个节点到根节点这一路上的所有路径和
    int dfs(TreeNode *root, int sum, vector<int> sumlist) {
        if (root == nullptr) {
            return 0;
        }

        // 将sumlist中的每个值都加上当前节点，更新和
        for (int i = 0; i < sumlist.size(); ++i) {
            sumlist[i] += root->val;
        }
        sumlist.emplace_back(root->val);

        int count = 0;
        for (int i = 0; i < sumlist.size(); ++i) {
            count += sumlist[i] == sum ? 1 : 0;
        }

        return count + dfs(root->left, sum, sumlist) + dfs(root->right, sum, sumlist);
    }
};
int main() {
    return 0;
}
