#include <bits/stdc++.h>

using namespace std;

/**
 * 感觉没什么好说的，模拟就好了
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        int L = nums[0], R = nums[0];
        vector<string> res;
        int n = nums.size();
        nums.push_back(INT_MAX);
        for (int i = 1; i < nums.size(); ++i) {
            if (i < n && nums[i] == nums[i - 1] + 1) {
                R = nums[i];
            } else {
                string s;
                if (L != R) {
                    s = to_string(L) + "->" + to_string(R);
                } else {
                    s = to_string(L);
                }
                res.push_back(s);
                L = nums[i];
                R = nums[i];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,2,4,5,7};
    const vector<string> &v = s.summaryRanges(nums);
    for (auto it : v) {
        cout << it << "  ";
    }
    cout << endl;
    return 0;
}

