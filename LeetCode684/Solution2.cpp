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
    // 邻接表
    vector<vector<int>> paths;

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vis.resize(n, false);

        // 邻接表存图
//        vector<vector<int>> paths(n, vector<int>());
        paths.resize(n + 1);
        for (vector<int> edge : edges) {
            paths[edge[0]].push_back(edge[1]);
            paths[edge[1]].push_back(edge[0]);
        }

        for (int i = edges.size() - 1; i >= 0; --i) {
            if (isALoopEdge(edges[i])) {
                return edges[i];
            }
        }

        return {};
    }

    bool isALoopEdge(vector<int> &edge) {
        vis[edge[0]] = true;
        vis[edge[1]] = true;
        for (int i = 0; i < paths[edge[0]].size(); ++i) {
            int u = paths[edge[0]][i];
            if (u == edge[1]) continue;
            else {
                vis[u] = true;
                if (hasAnotherPath(u, edge[1])) return true;
            }
        }
        return false;
    }

    bool hasAnotherPath(int begin, int end) {
        for (int i = 0; i < paths[begin].size(); ++i) {
            int u = paths[begin][i];
            if (!vis[u]) {
                vis[u] = true;
                if (hasAnotherPath(u, end)) {
                    vis[u] = false;
                    return true;
                } else {
                    vis[u] = false;
                }
            } else {
                if (u == end) {
                    return true;
                }
            }
        }
        return false;
    }
};


// int main() {
//     vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
//     Solution s;
//     s.findRedundantConnection(edges);
//     return 0;
// }

