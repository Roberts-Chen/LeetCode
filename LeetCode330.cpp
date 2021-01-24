#include <bits/stdc++.h>
using namespace std;

/*

    如果index < n并且nums[index] <= x，则令x = x + nums[index]，覆盖的区间就是[1, x + nums[index] - 1]
    否则的话就代表x没有被覆盖，就将x加入到nums中，覆盖的区间就是[1, 2x - 1]
 */
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int x = 1, index = 0, res = 0, len = nums.size();
        while (x <= n) {
            if (index < len && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x *= 2;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    cout << s.minPatches(nums, 8) << endl;
    return 0;
}

