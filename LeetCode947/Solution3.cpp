#include <iostream>
#include <vector>
#include <unordered_map                                 >
using namespace std;

/**
 * 方法三：并查集，将stones中的行和列进行和并，每一个行为x的石子和每一个列为y的石子都属于同一个联通分量
 * 最后只要看并查集的parent数组中有点的父亲节点是他自己即可
 */

class DisjointSetUnion {
private:
    // 父亲数组，用hash表实现
    unordered_map<int, int> parent;
    // 秩数组，用hash表实现
    unordered_map<int, int> rank;
public:
    int find(int x) {
        // 没找到x，就加入x
        if (!parent.count(x)) {
            parent[x] = x;
            rank[x] = 1;
            return x;
        }
        // 路径压缩
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        // 如果属于同一个连通分量
        if (fx == fy) {
            return;
        }
        // 按秩合并
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        parent[fy] = fx;
    }

    // 查找有多少个连通分量
    int numberOfConnectedComponent() {
        int num = 0;
        for (auto &[x, f] : parent) {
            if (x == f) {
                ++num;
            }
        }
        return num;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // 石子的数量
        int n = stones.size();
        DisjointSetUnion disjointSetUnion;
        for (int i = 0; i < n; ++i) {
            disjointSetUnion.unionSet(stones[i][0], stones[i][1] + 10001);
        }
        return n - disjointSetUnion.numberOfConnectedComponent();
    }
};


int main() {
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    int i = s.removeStones(stones);
    cout << i << endl;
    return 0;
}

