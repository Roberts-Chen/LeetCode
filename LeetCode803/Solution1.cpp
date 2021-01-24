#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

/**
 * 第一中方法，暴力法
 */
class Solution {
private:
    int dir[4][2] = {{-1, 0},
                     {0,  1},
                     {1,  0},
                     {0,  -1}};
    vector<bool> vis;
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        int x = grid.size(), y = grid[0].size(), n = hits.size();


        unordered_map<int, pair<int, int>> bricks;
        // 遍历grid一遍，记录下砖块的位置
        int num = 1;
        for (int i = 1; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (grid[i][j]) {
                    bricks[num] = make_pair(i, j);
                    grid[i][j] = num;
                    ++num;
                }
            }
        }


        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            vis.assign(n, false);
            int count = 0;
            int nums = grid[hits[i][0]][hits[i][1]];
            grid[hits[i][0]][hits[i][1]] = 0;
            bricks.erase(nums);
            for (auto &[_, p] : bricks) {
                if (!dfs(grid, p.first, p.second, x, y)) {
                    ++count;
                }
            }
            result[i] = count;
        }

        return result;
    }

    // 深度优先搜索，查看该点是否稳定
    bool dfs(vector<vector<int>> &grid, int i, int j, int x, int y) {
        if (i == 0) return true;
        for (int k = 0; k < 4; ++k) {
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];
            if (dx >= 0 && dx < x && dy >= 0 && dy < y && grid[dx][dy] && !vis[grid[dx][dy]]) {
                vis[grid[dx][dy]] = true;
                if (dfs(grid, dx, dy, x, y)) return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0},
                                {1, 1, 1, 0}};
    vector<vector<int>> hits = {{1, 0}};
    Solution s;
    const vector<int> &bricks = s.hitBricks(grid, hits);
    for (auto it : bricks) {
        cout << it << "  ";
    }
    cout << endl;
    return 0;
}

