#include <bits/stdc++.h>
using namespace std;

/**
 * 贪心，就是每次将元素加到最长的那个序列上去，然后判断剩余的元素是否能够组成
 * 一个由连续数字组成的长度大于3的序列，而判断能否加到最长序列上的条件是最长序列的最后一个元素
 * 是否是当前元素值减1，否则就开一个新的序列，如果这个新的序列需要组成一个长度为3的连续序列，则以当前
 * 元素num为头，后两位num+1，num+2都要在数组中且没有被其他序列使用。
 * @param nums
 * @return
 */
bool isPossible(vector<int>& nums) {
    unordered_map<int, int> mp1, mp2;
    for (int num : nums) {
        mp1[num]++;
    }
    for (int num : nums) {
        int countNum = mp1[num];
        if (countNum > 0) {
            if (mp2[num - 1] > 0) {
                mp2[num - 1] -= 1;
                mp2[num] += 1;
                mp1[num] = countNum - 1;
            } else {
                int countNum1 = mp1[num + 1], countNum2 = mp1[num + 2];
                if (countNum1 > 0 && countNum2 > 0) {
                    mp1[num] = countNum - 1;
                    mp1[num + 1] = countNum1 - 1;
                    mp1[num + 2] = countNum2 - 1;
                    mp2[num + 2] += 1;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * 使用哈希表和最小堆
 * 哈希表的键是序列末尾的值x，哈希表的值是以x结尾的序列的长度组成的最小堆
 * 遍历数组，每次得到一个以x结尾的序列，如果以x-1结尾的序列在哈希表中存在，
 * 就将以x-1结尾的序列删除一个（删除最小堆的堆顶），并且以x结尾的序列长度为该序列
 * 长度+1，若不存在，就设以x结尾的序列长度为1
 * @param nums
 * @return
 */
bool isPossible_2(vector<int>& nums) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int x : nums) {
        if (mp.find(x) == mp.end()) {
            mp[x] = priority_queue<int, vector<int>, greater<int>>();
        }
        if (mp.find(x - 1) != mp.end()) {
            int prev = mp[x - 1].top();
            mp[x - 1].pop();
            mp[x].push(prev + 1);
            if (mp[x - 1].empty()) {
                mp.erase(x - 1);
            }
        } else {
            mp[x].push(1);
        }
    }

    for (auto item : mp) {
        if (item.second.top() < 3) return false;
    }
    return true;
}


int main() {
    vector<int> nums = {1,2,3,3,4,5};
    cout << isPossible_2(nums) << endl;
    return 0;
}

