#include <bits/stdc++.h>
using namespace std;

/**
 * 这题就是LeetCode188. 买卖股票的最佳时机 IV的简化版，
 * 将只准买卖 k 次改成了只准买卖 2 次，
 * sell[i][j]表示在第i天完成j笔交易后未持有股票的最大利润
 * buy[i][j]表示在第i天完成j笔交易后持有股票的最大利润
 * sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i])
 * buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i])
 * 边界条件：
 *      sell[1...n][0] =
 *      buy[0][0] = -prices[0]
 *      sell[0][0] = 0
 *      sell[1...n][0] = 0
 *      buy[1...n][0] = max(buy[0][0], 0)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> sell(n, vector<int>(3, 0));
        vector<vector<int>> buy(n, vector<int>(3, 0));

        // 在第0天的时候，一笔交易都不可能完成，所以buy[0][1...k]和sell[0][1...k]
        // 都应该是一个极小的无效数字，防止对buy[0][0]和sell[0][0]产生干扰
        for (int i = 1; i < 3; ++i) {
            sell[0][i] = INT_MIN / 2;
            buy[0][i] = INT_MIN / 2;
        }

        sell[0][0] = 0;
        buy[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                if (j != 0) {
                    sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
                }
            }
        }
        printf("%d\t%d\t%d", sell[n - 1][0], sell[n - 1][1], sell[n - 1][2]);
        return max(sell[n - 1][1], sell[n - 1][2]);
    }
};

int main() {
    vector<int> prices = {7,6,4,3,1};
    Solution s;
    int i = s.maxProfit(prices);
    cout << i << endl;
    return 0;
}
