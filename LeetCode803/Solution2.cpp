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

class DisjointSetUnion {
private:
    int n;
    vector<int> rank;
    vector<int> parent;
public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        parent[fy] = fx;
    }

    int getNum() {
        return rank[0];
    }

    void setRank() {
        rank[0] = 0x3f3f3f;
    }
};

/**
 * 第二种方法，逆向思维，要求的是打掉砖块之后掉落多少砖块，而打砖块是把一个连通分量
 * 拆分成两个或多个连通分量的过程，所以，我们可以逆向的思考，由打变补，我们反着去补砖块，将
 * 打掉的砖块四周的连通分量合成一个连通分量，在这个过程中，连通分量中增加的节点数量就是
 * 打掉该砖块之后掉落的砖块数量
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
        int m = grid.size(), n = grid[0].size(), k = hits.size();

        // 先按顺序将所有要打的砖块打掉
        for (int i = 0; i < k; ++i) {
            if (!grid[hits[i][0]][hits[i][1]]) {
                // 如果本来就是0，那么改为-1，代表本来就是0
                grid[hits[i][0]][hits[i][1]] = -1;
            } else {
                // 如果本来不是0，就赋值为0
                grid[hits[i][0]][hits[i][1]] = 0;
            }
        }

        // num赋予代表每个砖块数字代号，brickNum代表砖块的数量
        int num = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    grid[i][j] = ++num;
                }
            }
        }

        // 初始化并查集
        DisjointSetUnion disjointSetUnion(num + k + 1);
        disjointSetUnion.setRank();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    if (i == 0) {
                        disjointSetUnion.unionSet(0, grid[i][j]);
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] > 0) {
                        disjointSetUnion.unionSet(grid[i - 1][j], grid[i][j]);
                    }
//                    if (i + 1 < m && grid[i + 1][j] > 0) {
//                        disjointSetUnion.unionSet(grid[i + 1][j], grid[i][j]);
//                    }
                    if (j - 1 >= 0 && grid[i][j - 1] > 0) {
                        disjointSetUnion.unionSet(grid[i][j - 1], grid[i][j]);
                    }
//                    if (j + 1 < n && grid[i][j + 1] > 0) {
//                        disjointSetUnion.unionSet(grid[i][j + 1], grid[i][j]);
//                    }
                }
            }
        }


        // 补砖块
        vector<int> res(k, 0);
        for (int i = k - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == -1) {
                res[i] = 0;
                continue;
            }
            int prev = disjointSetUnion.getNum();
            grid[x][y] = ++num;
            if (x == 0) {
                disjointSetUnion.unionSet(0, grid[x][y]);
            }
            if (x - 1 >= 0 && grid[x - 1][y] > 0) {
                disjointSetUnion.unionSet(grid[x - 1][y], grid[x][y]);
            }
            if (x + 1 < m && grid[x + 1][y] > 0) {
                disjointSetUnion.unionSet(grid[x + 1][y], grid[x][y]);
            }
            if (y - 1 >= 0 && grid[x][y - 1] > 0) {
                disjointSetUnion.unionSet(grid[x][y - 1], grid[x][y]);
            }
            if (y + 1 < n && grid[x][y + 1] > 0) {
                disjointSetUnion.unionSet(grid[x][y + 1], grid[x][y]);
            }
            int current = disjointSetUnion.getNum();
            res[i] = max(0, current - prev - 1);
        }
        return res;
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
    vector<vector<int>> grid = {{1, 0, 1},
                                {1, 1, 1}};
    vector<vector<int>> hits = {{0, 0}, {0, 2}, {1, 1}};
    Solution s;
    const vector<int> &bricks = s.hitBricks(grid, hits);
    for (auto it : bricks) {
        cout << it << "  ";
    }
    cout << endl;
    return 0;
}
/*
[[1,0,1],[1,1,1]]
[[0,0],[0,2],[1,1]]
 */

