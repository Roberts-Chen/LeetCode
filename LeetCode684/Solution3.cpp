#include <bits/stdc++.h>
using namespace std;


/**
 * 解法三：并查集
 */

class UnionSet {
private:
    int n;
    vector<int> rank;
    vector<int> parent;
public:
    UnionSet(int _n) {
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
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        UnionSet unionSet(n + 1);
        for (int i = 0; i < n; ++i) {
            if (unionSet.find(edges[i][0]) == unionSet.find(edges[i][1])) {
                return edges[i];
            } else {
                unionSet.unionSet(edges[i][0], edges[i][1]);
            }
        }
        return {};
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2},
                                 {2, 3},
                                 {3, 4},
                                 {1, 4},
                                 {1, 5}};
    Solution s;
    const vector<int> &vector = s.findRedundantConnection(edges);
    for (auto i : vector) {
        cout << i << endl;
    }
    return 0;
}

