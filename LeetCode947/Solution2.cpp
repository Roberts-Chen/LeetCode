#include <bits/stdc++.h>
using namespace std;

/**
 * 方法二：深度优先搜索，比方法一在建图策略上有所优化
 */
class Solution {
private:
    unordered_map<int, vector<int>> rec;
    vector<vector<int>> graph;
    vector<bool> vis;
public:
    int removeStones(vector<vector<int>>& stones) {
        // 石子的数量
        int n = stones.size();

        // 用哈希表存储每一行和每一列拥有的所有石子（存储他们在stones中的索引）
        // 把列标加上10001来区分行标和列标，因此可以用同一张哈希表，不会冲突
        for (int i = 0; i < n; ++i) {
            rec[stones[i][0]].push_back(i);
            rec[stones[i][1] + 10001].push_back(i);
        }


        // 建图，把每一行的k个石子用k-1条边连接起来作为一个连通域
        // 其实，不管这k个石子怎么联通，最优的移除方法都是只剩下一个，所以可以简略的用k-1条边连接
        // 最终dfs都会访问到所有的点
        graph.resize(stones.size());
        for (auto &it : rec) {
            int k = it.second.size();
            for (int i = 1; i < k; ++i) {
                graph[it.second[i - 1]].push_back(it.second[i]);
                graph[it.second[i]].push_back(it.second[i - 1]);
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
