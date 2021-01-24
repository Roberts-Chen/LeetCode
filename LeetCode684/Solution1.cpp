#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 环的起点和终点
    int begin, end;
    // 点的访问状态
    vector<bool> vis;
    // 判断是否有环
    bool hasCircle = false;
    // 环中所有的边
    vector<int> circle_points;

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vis.resize(n, false);

        // 邻接表存图
        vector<vector<int>> paths(n, vector<int>());
        for (vector<int> edge : edges) {
            paths[edge[0]].push_back(edge[1]);
            paths[edge[1]].push_back(edge[0]);
        }

        // 寻找环的终点和起点
        for (int i = 1; i <= n && !hasCircle; ++i) {
            vis[i] = true;
            find_circle(paths, i, i);
            vis[i] = false;
        }

        // cout << "begin: " << begin << "  end: " << end << endl;

        // 寻找环中所有的连接边
        vis.assign(n, false);
        vis[begin] = true;
        find_circle_all_point(paths, begin);
        for (int i = 1; i < n; ++i) {
            if (vis[i]) circle_points.push_back(i);
            // cout << i << "  " <<  vis[i] << endl;
        }



        for (int i = edges.size() - 1; i >= 0; --i) {
            if (vis[edges[i][0]] && vis[edges[i][1]]) {
                return edges[i];
            }
        }

        return {};
    }

    // 寻找环的起点和终点
    void find_circle(vector<vector<int>> &paths, int v, int u) {
        for (int i = 0; i < paths[v].size(); ++i) {
            if (!vis[paths[v][i]]) {
                vis[paths[v][i]] = true;
                find_circle(paths, paths[v][i], v);
                vis[paths[v][i]] = false;
            } else {
                if (paths[v][i] != u && !hasCircle) {
                    // 访问到上一次被访问过的端点了，就判断为有环
                    begin = paths[v][i];
                    end = v;
                    hasCircle = true;
                }
            }
        }
    }

    // 寻找环中所有的边
    bool find_circle_all_point(vector<vector<int>> &paths, int v) {
        for (int i = 0; i < paths[v].size(); ++i) {
            int u = paths[v][i];
            if (!vis[u]) {
                vis[u] = true;
                if (!find_circle_all_point(paths, u)) {
                    vis[u] = false;
                } else {
                    return true;
                }
            } else {
                if (u == begin && v == end) {
                    return true;
                }
            }
        }
        return false;
    }
};