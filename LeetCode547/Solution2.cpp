#include <bits/stdc++.h>

using namespace std;

/**
 * 遍历所有城市，如果有城市尚未被访问，就对该城市进行访问，并将省份数量加一，然后
 * 对与该城市相连的所有城市进行DFS访问
 */
class Solution {
private:
    int res;
    vector<bool> vis;
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vis.resize(n, false);
        res = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++res;
                dfs(isConnected, i);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &isConnected, int u) {
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[u][i] && !vis[i]) {
                vis[i] = true;
                dfs(isConnected, i);
            }
        }
    }
};





