#include <bits/stdc++.h>

using namespace std;

/**
 * 解法二：优先级队列
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});
        }

        res.push_back(pq.top().first);
        for (int l = 0, r = k; r < n; ++r, ++l) {
            while (!pq.empty() && l >= pq.top().second) {
                pq.pop();
            }
            pq.push({nums[r], r});
            res.push_back(pq.top().first);
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
    vector<int> res = s.maxSlidingWindow(nums, 5);
    for (int i : res) {
        printf("%d  ", i);
    }
    return 0;
}

