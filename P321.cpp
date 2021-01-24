#include <bits/stdc++.h>

using namespace std;

/**
 * 比较两个数组的大小
 * @param nums1
 * @param index1
 * @param nums2
 * @param index2
 * @return
 */
int compare(vector<int> &nums1, int index1, vector<int> &nums2, int index2) {
    int x = nums1.size(), y = nums2.size();
    while (index1 < x && index2 < y) {
        int dis = nums1[index1] - nums2[index2];
        if (dis != 0) {
            return dis;
        }
        ++index1;
        ++index2;
    }
    return (x - index1) - (y - index2);
}

/**
 * 从一个数组中选取k个值，并保证k个值的顺序不变并且组成的数最大
 * @param nums
 * @param k
 * @return
 */
vector<int> selectMax(vector<int> &nums, int k) {
//    if (k == 0) return {};
//    int drop = nums.size() - k;
//    vector<int> stack;
//    for (int num : nums) {
//        while (drop > 0 && !stack.empty() && stack.back() < num) {
//            stack.pop_back();
//            --drop;
//        }
//        stack.push_back(num);
//    }
//    return vector<int>(stack.begin(), stack.begin() + k);
    int length = nums.size();
    vector<int> stack(k, 0);
    int top = -1;
    int remain = length - k;
    for (int i = 0; i < length; i++) {
        int num = nums[i];
        while (top >= 0 && stack[top] < num && remain > 0) {
            top--;
            remain--;
        }
        if (top < k - 1) {
            stack[++top] = num;
        } else {
            remain--;
        }
    }
    return stack;
}

vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();

    if (m == 0) {
        return nums2;
    }

    if (n == 0) {
        return nums1;
    }

    int mergedLength = m + n;
    vector<int> res(mergedLength);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < mergedLength; ++i) {
        if (compare(nums1, index1, nums2, index2) > 0) {
            res[i] = nums1[index1++];
        } else {
            res[i] = nums2[index2++];
        }
    }
    return res;
}



vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> res(k, 0);
    int m = nums1.size(), n = nums2.size();
    int start = max(0, k - n), end = min(k, m);
    for (int i = start; i <= end; ++i) {
        vector<int> maxNums1 = selectMax(nums1, i);
        vector<int> maxNums2 = selectMax(nums2, k - i);
        vector<int> curMaxNums(merge(maxNums1, maxNums2));
        if (compare(curMaxNums, 0, res, 0) > 0) {
            res.swap(curMaxNums);
        }
    }
    return res;
}

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> maxSubsequence(k, 0);
        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; i++) {
            vector<int> subsequence1(MaxSubsequence(nums1, i));
            vector<int> subsequence2(MaxSubsequence(nums2, k - i));
            vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;
    }

    vector<int> MaxSubsequence(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> stack(k, 0);
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }
        return stack;
    }

    vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};

int main() {
    vector<int> nums1 = {6, 7};
    vector<int> nums2 = {6, 0, 4};
//    auto it = selectMax(nums2, 3);
//    for (int i : it) {
//        cout << i << " ";
//    }
//    cout << endl;
//    auto it = maxNumber(nums1, nums2, 5);
//    for (int i : it) {
//        cout << i << " ";
//    }
//    cout << endl;
//    auto item = merge(selectMax(nums1, 2), selectMax(nums2, 3));
//    for (int it : item) {
//        cout << it << "  ";
//    }
//    cout << endl;
    auto item = maxNumber(nums1, nums2, 5);
    for (int it : item) {
        cout << it << "  ";
    }
    cout << endl;
//    Solution s;
//    auto item = s.maxNumber(nums1, nums2, 5);
//    for (int it : item) {
//        cout << it << "  ";
//    }
//    cout << endl;
    return 0;
}

