#include <bits/stdc++.h>

using namespace std;

/**
 * 解法一：单调队列，队列头存储滑动窗口中最大的那个元素
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        for (int l = 0, r = k; r < n; ++r, ++l) {
            if (nums[l] == dq.front()) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[r] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[r]);
            res.push_back(dq.front());
        }

        return res;
    }
};
