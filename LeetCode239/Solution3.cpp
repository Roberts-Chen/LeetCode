#include <bits/stdc++.h>

using namespace std;

/**
 * 解法三：分块+预处理
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        for (int i = 0; i < n; ++i) {
            if (i % k == 0) {
                prefixMax[i] = nums[i];
            } else {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                suffixMax[i] = nums[i];
            } else if ((i + 1) % k == 0) {
                suffixMax[i] = nums[i];
            } else {
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n - k + 1; ++i) {
            res.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
//    priority_queue<int> pq;
//    for (int num : nums) {
//        pq.push(num);
//    }
//    while (!pq.empty()) {
//        cout << pq.top() << "  ";
//        pq.pop();
//    }
//    cout << endl;
    Solution s;
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for (int i : res) {
        printf("%d  ", i);
    }
    return 0;
}
