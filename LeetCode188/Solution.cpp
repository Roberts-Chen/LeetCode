#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 动态规划
     * buy[i][j]表示为在第i天时进行了j次交易手中持有股票的最大利益
     * sell[i][j]表示为在第i天时进行了j次交易手中不持有股票的最大利益
     * 转移方程：
     *      buy[i][j] = max{buy[i - 1][j], sell[i - 1][j] - prices[i]};
     *      sell[i][j] = max{sell[i - 1][j], sell[i - 1][j - 1] + prices[i]};
     * 边界条件：
     *      buy[0][1...k] = INT_MIN / 2, buy[0][0] = -prices[0]
     *      sell[0][1...k] = INT_MIN / 2, sell[0][0] = 0
     *
     *      buy[i][j]=max{buy[i−1][j],sell[i−1][j]−price[i]}
     *      sell[i][j]=max{sell[i−1][j],buy[i−1][j−1]+price[i]}
     * @param k
     * @param prices
     * @return
     */
//    int maxProfit(int k, vector<int> &prices) {
//        int n = prices.size();
//        k = min(k, n / 2);
//        vector<vector<int>> buy(n, vector<int>(k + 1, 0));
//        vector<vector<int>> sell(n, vector<int>(k + 1, 0));
//        for (int i = 1; i <= k; ++i) {
//            buy[0][i] = INT_MIN / 2;
//            sell[0][i] = INT_MIN / 2;
//        }
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j <= k; ++j) {
//                if (i != 0) {
//                    buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
//                    if (j != 0) {
//                        sell[i][j] = max(sell[i - 1][j], sell[i - 1][j - 1] + prices[i]);
//                    }
//                }
//            }
//        }
//
//        return *max_element(sell[n - 1].begin(), sell[n - 1].begin() + k);
//    }

    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<int> buy(k + 1);
        vector<int> sell(k + 1);

        buy[0] = -prices[0];
        sell[0] = 0;

//        for (int i = 1; i < n; ++i) {
//            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
//            for (int j = 1; j <= k; ++j) {
//                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
//                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
//            }
//        }

        for (int i = 0; i <= k; ++i) {
            buy[i] = max(buy[i], sell[i] - prices[i]);
            if (i != 0) {
                sell[i] = max(sell[i], buy[i - 1] + prices[i]);
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};

/*
 *
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iv-by-8xtkp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */