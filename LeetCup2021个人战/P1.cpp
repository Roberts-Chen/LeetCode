#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        long long res = 0, mod = 1000000007;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            left = i + 1, right = nums.size();
            int num = target - nums[i];
            while (left < right) {
                int mid = (right - left) / 2 + left;
                if (nums[mid] <= num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            res = (res + left - i - 1) % mod;
        }
        return res % mod;
    }
};
// 2 3 5 5
int main() {
    Solution s;
    vector<int> nums = {2,2,1,9};
    int target = 10;
    int i = s.purchasePlans(nums, target);
    cout << i << endl;
    return 0;
}

