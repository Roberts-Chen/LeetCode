//
// Created by 22577 on 2021/1/23.
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

/*
深度优先搜索：
    每次选最大的那个，不行就回溯

*/
class Solution {
private:
    map<int, int> memo;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        sort(coins.begin(), coins.end());
        int res = dfs(coins, amount);

        for (auto it : memo) {
            cout << it.first << "->" << it.second << endl;
        }

        return res == INT_MAX ? -1 : res;

    }

    int dfs(vector<int> &coins, int amount) {
        if (amount < 0) {
            return INT_MAX;
        }
        if (amount == 0) {
            return 0;
        }

        if (memo.count(amount)) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (int i = 0; i < coins.size(); ++i) {
            int ans = dfs(coins, amount - coins[i]);
            if (ans != INT_MAX) {
                res = min(res, ans + 1);
            }
//            res = min(res, dfs(coins, amount - coins[i]));
        }
        memo[amount] = res;
        return res;
    }
};


int main() {
    Solution s;
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
    int i = s.coinChange(coins, amount);
    cout << i << endl;
    return 0;
}
