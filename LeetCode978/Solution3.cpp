#include <vector>
#include <iostream>

using namespace std;

/**
 * 动态规划
 * dp[i][0]表示以A[i]结尾的湍流子数组的最大长度，且A[i - 1] > A[i]；
 * dp[i][1]表示以A[i]结尾的湍流子数组的最大长度，且A[i - 1] < A[i]；
 *
 * 对于A[i - 1] > A[i]而言，如果A[i]要构成湍流子数组，则需考虑i - 1 = 0或者
 * i - 1 > 0 且 A[i - 2] < A[i - 1]，所以dp[i][0] = dp[i - 1][1] + 1，dp[1][0] = 1
 *
 * 对于A[i - 1] < A[i]而言，如果A[i]要构成湍流子数组，则需考虑i - 1 = 0或者
 * i - 1 > 0 且 A[i - 2] > A[i - 1]，所以dp[i][1] = dp[i - 1][0] + 1，dp[1][1] = 1
 *
 * 对于A[i - 1] == A[i]而言，直接令dp[i][0] = dp[i][1] = 1
 *
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        int n = arr.size();
        int res = 1;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
                res = max(res, dp[i][1]);
            } else if (arr[i] < arr[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1;
                res = max(res, dp[i][0]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,8,4,12,4};
    int res = s.maxTurbulenceSize(nums);
    cout << res << endl;
    return 0;
}
