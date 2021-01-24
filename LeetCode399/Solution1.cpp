#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<bool> vis;
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int n = equations.size();
        unordered_map<string, int> str2int;
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (!str2int.count(equations[i][0])) {
                str2int[equations[i][0]] = num++;
            }
            if (!str2int.count(equations[i][1])) {
                str2int[equations[i][1]] = num++;
            }
        }
        vector<vector<pair<int, double>>> path(num, vector<pair<int, double>>());
        for (int i = 0; i < n; i++) {
            auto e = equations[i];
            path[str2int[e[0]]].push_back({str2int[e[1]], values[i]});
            path[str2int[e[1]]].push_back({str2int[e[0]], 1.0 / values[i]});
        }


        for (int i = 0; i < path.size(); i++) {
            for (int j = 0; j < path[i].size(); ++j) {
                cout << path[i][j].first << "  " << path[i][j].second << "  ";
            }
            cout << endl;
        }

        vector<double> res;

        // 使用广度优先搜索判断两点之间是否可达
        for (int i = 0; i < queries.size(); ++i) {
            auto q = queries[i];
            queue<pair<int, double>> que;
            if (!str2int.count(q[0]) || !str2int.count(q[1])) {
                res.push_back(-1);
                continue;
            }
            que.push({str2int[q[0]], 1.0});
            vis.resize(num, false);
            while (!que.empty()) {
                auto v = que.front();
                que.pop();
                cout << "v:  " << v.first << "   " << v.second << endl;
                if (v.first == str2int[q[1]]) {
                    res.push_back(v.second);
                    break;
                }
                for (int j = 0; j < path[v.first].size(); ++j) {
                    int u = path[v.first][j].first;
                    if (!vis[u]) {
                        vis[u] = true;
                        path[v.first][j].second *= v.second;
                        que.push(make_pair(u, path[v.first][j].second));
                        // cout << "u: " << u << "  path[v.first][j].second:  " << path[v.first][j].second << endl;
                    }
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}

/*
 * path[v.first].size()v:  0   1
path[v.first].size: 1u: 1 j: 0
v:  1   2
path[v.first].size: 2u: 0 j: 0
path[v.first].size: 2u: 2 j: 1
v:  0   1
path[v.first].size: 1u: 1 j: 0
v:  2   6
6
v:  1   1
path[v.first].size: 2 u: 0 j: 0
path[v.first].size: 2 u: 2 j: 1
v:  -1094795586   -1.83255e-06


v:  0   1
u: 1  path[v.first][j].second:  2
v:  1   2
u: 0  path[v.first][j].second:  1
u: 2  path[v.first][j].second:  6
v:  0   1
v:  2   6
6
v:  1   1
v:  -1094795586   -1.83255e-06

[["a","b"],["b","c"]]
[2.0,3.0]
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
[["a","b"],["b","c"],["bc","cd"]]
[1.5,2.5,5.0]
[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
[["a","b"]]
[0.5]
[["a","b"],["b","a"],["a","c"],["x","y"]]
 */