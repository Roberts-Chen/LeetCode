#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int numsLength = nums.size();
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        int bucketSize = (maxValue - minValue) / (numsLength - 1);
        int bucketLength = (maxValue - minValue) / bucketSize + 1;
        vector<pair<int, int>> bucket(bucketLength, {INT_MAX, INT_MIN});

        for (int i = 0; i < numsLength; ++i) {
            int idx = (nums[i] - minValue) / bucketSize;
            bucket[idx].first = min(bucket[idx].first, nums[i]);
            bucket[idx].second = max(bucket[idx].second, nums[i]);
        }

        int pre = INT_MAX, maxGap = INT_MIN;
        for (int i = 0; i < bucketLength; ++i) {
            if (bucket[i].first != INT_MAX && pre != INT_MAX) {
                maxGap = max(maxGap, bucket[i].first - pre);
            }

            if (bucket[i].first != INT_MAX) {
                maxGap = max(maxGap, bucket[i].second - bucket[i].first);
                pre = bucket[i].second;
            }
        }

        return maxGap;
    }
};

int main() {
    vector<int> nums = {5, 3, 1, 8 ,9, 7, 4, 6};
    // [1, 3, 4, 5, 6, 7, 8, 9]
    // [1,3] [3,4] [4,5] [5,6] [6,7] [7,8] [8,9] [9,9]
    // [1,1] [INT_MAX,INT_MIN] [3,3] [4,4] [5,5] [6,6] [7,7] [8,8] [9,9]
    // 分成了9个桶，每个桶一个元素
    Solution s;
    cout << s.maximumGap(nums) << endl;
    reverse()
    return 0;
}
