#include <bits/stdc++.h>
using namespace std;

/**
 * 贪心算法：
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 * 这个问题其实可以反过来思考：在一个区间集合中，取出数量最多的不重叠区间，那么剩下的区间就一定是跟这些被取出来的区间有重叠的
 * 先来思考一个问题：在所有的重叠区间中，我们应该保留哪个区间？
 * |-----|
 *   |-----|
 *    |-----------|
 *              |---------|
 * 上面三个重叠的区间，我们最应该保留的是右端点最小的区间，为什么？因为右端点最小的那个区间，删除右端点大的那个区间，可以使整个集合中的不重叠区间
 * 数量最大
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // 将集合中的区间按照右端点升序排序
        sort(intervals.begin(), intervals.end(), [](vector<int> &u, vector<int> &v) {
            if (u[1] != v[1]) {
                return u[1] < v[1];
            } else {
                return u[0] < v[0];
            }
        });
        int r = intervals[0][1];
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= r) {
                ++res;
                r = intervals[i][1];
            }
        }
        return n - res;
    }
};

int main() {
    vector<vector<int>> intervals = {{2,3}, {1,2}, {1,3}, {3,4}};
    Solution s;
    cout << s.eraseOverlapIntervals(intervals);
    return 0;
}
