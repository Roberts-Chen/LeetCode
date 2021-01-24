#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 有两种状态
     * 1、持股
     *      1、今天不做事
     *      2、今天买入
     * 2、不持股
     *      1、今天不做事
     *      2、今天卖出
     * @param prices
     * @return
     */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[n - 1][1];
    }
};

int main() {
    return 0;
}

