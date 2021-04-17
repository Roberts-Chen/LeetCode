#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    intervals.push_back({INT_MAX, INT_MAX});
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int t = intervals[0][1], left = intervals[0][0];
    for (int i = 0; i < n; ++i) {
        if (intervals[i][0] <= t) {
            t = min(intervals[i][1], t);
            left = max(intervals[i][0], left);
        } else {
            res.push_back({left, t});
            left = intervals[i][0];
            t = intervals[i][1];
        }
    }
    return res;
}

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) {
        return 0;
    }
    // 将所有气球的直径左右坐标按右端点进行升序排序
    sort(points.begin(), points.end(), [](const vector<int> &u, const vector<int> &v){
        return u[1] < v[1];
    });
    int t = points[0][1], res = 0, n = points.size();
    for (const vector<int> &balloon : points) {
        if (balloon[0] > t) {
            ++res;
            t = balloon[1];
        }
    }
    return res;
}

int main() {
    vector<vector<int>> cur = {{10,16},{2,8},{1,6},{7,12}};
    auto it = merge(cur);
    for (auto i : it) {
        cout << "[" << i[0] << "," << i[1] << "]" << endl;
    }
    cout << findMinArrowShots(cur) << endl;
    return 0;
}

