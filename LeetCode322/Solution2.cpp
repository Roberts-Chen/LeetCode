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

/**
 * 解法二：动态规划，和回溯的思路类似，可以把每次求得的余额看成是一个子问题，
 * 它需要最少需要多少硬币来组成呢？我们转而又去求它的解
 * 不妨设amount=x, coins = [c1, c2, ..., cn]
 * 而dp[x]表示使用coins中的硬币组成x所需的最小硬币数量
 * 则dp[x] = min{dp[x - coins[1]], dp[x - coins[2]], dp[x - coins[3]], ..., dp[x - coins[n]]} + 1
 *
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount];
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
