#include <bits/stdc++.h>

using namespace std;

/**
 * [A1,A2,A3,...,An-2,An-1,An]
 * [5,7,7,8,8,10]
 *  0,1,2,3,4,5
 * @param nums
 * @param target
 * @return
 */
int findTheFirstIndex(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (nums[left] == target && right < left) {
        return left;
    }
    return -1;
}

/**
 * [5,7,7,8,8,10]
 *  0,1,2,3,4,5
 * @param nums
 * @param target
 * @return
 */
int findTheLastIndex(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right;
}

int binarySerach(vector<int> &nums, int target, bool lower) {
    if (nums.size() == 0) return -1;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums[mid] == target) {
            lower ? right = mid - 1 : left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (lower && left != nums.size() && nums[left] == target) {
        return left;
    }
    if (!lower && right != -1 && nums[right] == target) {
        return right;
    }
    return -1;
}

/**
 * 经典二分
 * @param nums
 * @param target
 * @return
 */
vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 0) {
        return {-1, -1};
    }
//    int begin = findTheFirstIndex(nums, target);
//    cout << begin << endl;
//    if (begin == -1) return {-1, -1};
//    int end = findTheLastIndex(nums, target);
    int begin = binarySerach(nums, target, true);
    int end = binarySerach(nums, target, false);
    return {begin, end};
}


int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto it = searchRange(nums, 9);
    cout << it[0] << "  " << it[1] << endl;
//    vector<int> nums = {1,5,1,5,3,3,6};
//    int res = 0;
//    for (int i = 0; i < nums.size(); ++i) {
//        res ^= nums[i];
//    }
//    cout << res << endl;
    return 0;
}

