#include <bits/stdc++.h>
using namespace std;

/**
 * 方法一：深度优先搜索，每个石子可以看作图的一个端点，而与石子同行或同列的石子可以看作与该石子相连的
 * 端点，这个图是一个无向图，对于这样一个无向图，我们可以通过调整移除的端点的顺序来使得图中只剩下一个石子，
 * 而我们所要求的就是这样的连通分支有多少，每个连通分支中最后会只剩下一个石子，所以可删除的石子的最大数量
 * 为：石子的总数-连通分支数
 */
class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> vis;
public:
    int removeStones(vector<vector<int>>& stones) {
        // 石子的数量
        int n = stones.size();


        // 建图
        graph.resize(stones.size());
        for (int i = 0; i < n; ++i) {
            int row = stones[i][0], col = stones[i][1];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    if (stones[j][0] == row || stones[j][1] == col) {
                        // 跟点(row, col)同行的点
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }

        // 开始查找连通分支
        // 联通分支数量
        int nums = 0;
        vis.resize(n, false);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ++nums;
                vis[i] = true;
                dfs(i);
            }
        }

        return n - nums;
    }

    void dfs(int v) {
        for (int i = 0; i < graph[v].size(); ++i) {
            if (!vis[graph[v][i]]) {
                vis[graph[v][i]] = true;
                dfs(graph[v][i]);
            }
        }
    }
};


int main() {
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    int i = s.removeStones(stones);
    cout << i << endl;
    return 0;
}
