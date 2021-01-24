#include <bits/stdc++.h>
using namespace std;

/**
 * 这题就是LeetCode188. 买卖股票的最佳时机 IV的简化版，
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
            cout << "===============" << endl;
            cout << "buy1: " << buy1 << " sell1: " << sell1 << " buy2: " << buy2 << " sell2: " << sell2 << endl;
        }
        return sell2;
    }
};

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution s;
    int i = s.maxProfit(prices);
    cout << i << endl;
    return 0;
}


