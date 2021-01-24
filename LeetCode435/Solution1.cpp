#include <bits/stdc++.h>
using namespace std;

/**
 * 解决方法1：动态规划
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 * 这个问题其实可以反过来思考：在一个区间集合中，取出数量最多的不重叠区间，那么剩下的区间就一定是跟这些被取出来的区间有重叠的
 * 为了更好的确定区间之间是否有重叠，我们可以将集合中的区间排个序（按照左端点升序或者按照右端点升序）。遍历集合中的所有区间，以每一个当前区间
 * 为最后一个取出的区间，统计最多可以取出几个区间，转移方程：fi = max{ fj( j < i & rj < li ) } + 1
 * 最后的结果就是集合中的区间个数减去fi中的最大值 result = n - max{fi}
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> f(n, 0);
        sort(intervals.begin(), intervals.end(), [](vector<int> &u, vector<int> &v) {
            if (u[0] != v[0]) {
                return u[0] < v[0];
            } else {
                return u[1] < v[1];
            }
        });
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (intervals[i][0] >= intervals[j][1]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += 1;
            res = max(res, f[i]);
        }
        return n - res;
    }
};

int main() {
    vector<vector<int>> intervals = {{2,3}, {1,2}, {1,3}, {3,4}};
    Solution s;
    s.eraseOverlapIntervals(intervals);
    return 0;
}
