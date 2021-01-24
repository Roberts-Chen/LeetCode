#include <bits/stdc++.h>
using namespace std;

/**
 * 遍历所有城市，如果有城市尚未被访问过，就将省份+1，并访问该城市并对于该城市相连的
 * 城市进行BFS，访问与该城市相连的所有城市
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            ++res;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    if (isConnected[v][j] && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
            }
        }

        return res;
    }
};

