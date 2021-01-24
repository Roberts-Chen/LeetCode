#include "../HelpHeaders.h"

using namespace std;

/**
 * @brief 并查集实现
 */
class UnionFind {
private:
    int n;
    vector<int> rank;
    vector<int> parent;
public:
    int setCount;

    UnionFind(int _n) {
        n = _n;
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        setCount = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        parent[fy] = fx;
        --setCount;
        return true;
    }
};

/*
    方法一：Kruskal算法判断最小生成树
    几个概念要搞清楚，什么是关键边，什么是非关键边？
        关键边：
            如果从图中删去某条边，会导致最小生成树的权值和增加。如果原图的最小生成树权值为value，
            那么删除这条边后有两种情况：
                1、整个图不连通，不存在最小生成树；
                2、整个图联通，存在最小生成树，但是最小生成树的权值v严格大于value；
        伪关键边：
            可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。既然伪关键边可能会出现在某些
            最小生成树中，那么我们可以在最开始的时候就将这条边两个点联通，如果最后得到的最小生成树的权值
            v等于value，就说明这条边是伪关键边。
        这道题最关键的就是高清楚：关键边和伪关键边的定义，关键边被删除后不仅仅可以使得最小生成树的权值增加，还可能使得
        图不连通，从而整个图种不存在最小生成树。而伪关键边则是一定会存在于某一个最小生成树中的边，所以我们在生成最小生
        成树的过程中可以【优先考虑】该边，首先将该边的两个端点合并，如果最后能够得到最小生成树并且权值等于value，就说
        明该边是一条【伪关键边】。
 */
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        // 边的数量
        int m = edges.size();

        // 给所有边添加一个它在edges中的下标值
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }

        // 将边按权值从小到大排序
        sort(edges.begin(), edges.end(), [&](const vector<int> &u, const vector<int> &v) {
            return u[2] - v[2];
        });

        // 先通过Kruskal算法得到最小生成树的权值value
        UnionFind uf_1(n);
        int value = 0;
        for (int i = 0; i < m; ++i) {
            // 如果两个端点不属于同一个连通分量，则代表合并成功
            if (uf_1.unionSet(edges[i][0], edges[i][1])) {
                value += edges[i][2];
            }
        }

        vector<vector<int>> res(2);
        for (int i = 0; i < m; ++i) {

            // 判断是否为关键边
            UnionFind uf_2(n);
            int v = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && uf_2.unionSet(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            // 如果是关键边，则：
            // 1、整个图不连通，不存在最小生成树；
            // 2、整个图联通，存在最小生成树，但是最小生成树的权值v严格大于value；
            if (uf_2.setCount != 1 || (uf_2.setCount == 1 && v > value)) {
                res[0].push_back(edges[i][3]);
            }

            // 判断是否为伪关键边
            uf_2 = UnionFind(n);
            v = 0;
            uf_2.unionSet(edges[i][0], edges[i][1]);
            for (int j = 0; j < m; ++j) {
                if (i != j && uf_2.unionSet(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }

            // 如果是伪关键边，则：
            // 必然能够生成最小生成树并且得到的最小生成树的权值v必然等于value
            if (uf_2.setCount == 1 && v == value) {
                res[1].push_back(edges[i][3]);
            }
        }

        return res;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 1},
                                 {1, 2, 1},
                                 {2, 3, 2},
                                 {0, 3, 2},
                                 {0, 4, 3},
                                 {3, 4, 3},
                                 {1, 4, 6}};
    Solution s;
    const vector<vector<int>> &criticalEdges = s.findCriticalAndPseudoCriticalEdges(n, edges);
    for (int i = 0; i < criticalEdges.size(); ++i) {
        for (int j = 0; j < criticalEdges[i].size(); ++j) {
            cout << criticalEdges[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

