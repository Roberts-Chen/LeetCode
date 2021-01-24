#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划方法求斐波那契数列的第n项
 */
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.fib(3) << endl;
    return 0;
}

