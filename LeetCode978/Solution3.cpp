#include <vector>
#include <iostream>

using namespace std;

/**
 * 动态规划，空间优化，因为dp[i]之和dp[i - 1]有关，所以可以设置两个变量dp0和dp1
 * 将空间复杂度优化为：O(1)
 *
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        int n = arr.size();
        int res = 1, dp0 = 1, dp1 = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                dp1 = dp0 + 1;
                dp0 = 1;
                res = max(res, dp1);
            } else if (arr[i] < arr[i - 1]) {
                dp0 = dp1 + 1;
                dp1 = 1;
                res = max(res, dp0);
            } else {
                dp0 = dp1 = 1;
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
