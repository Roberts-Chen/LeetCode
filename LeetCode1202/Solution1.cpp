#include <bits/stdc++.h>
using namespace std;

class DisjoinSetUnion {
private:
    // 树的根节点
    vector<int> f;
    // 树的节点数量，包含根节点
    vector<int> rank;
    // 并查集的规模
    int n;
public:
    DisjoinSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
    }

    int find(int x) {
        // 查找父亲节点并进行路径压缩
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    void unionSet(int x, int y) {
        // 寻找x和y的父节点
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return;
        }
        // 默认fx为节点较大的那棵树的根节点，fy为节点较小的那棵树的根节点，不满足就交换一下
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        // 节点数量增加
        rank[fx] += rank[fy];
        // 将节点数量较小的树挂载到节点数量较大的树上去
        f[fy] = fx;
    }
};

class Solution {

public:

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DisjoinSetUnion setUnion(n);
        // 将所有索引对作为并查集的树拼接到
        for (auto& it : pairs) {
            setUnion.unionSet(it[0], it[1]);
        }
        unordered_map<int, priority_queue<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[setUnion.find(i)].push(s[i]);
        }
        for (int i = 0; i < s.length(); ++i) {
            int x = setUnion.find(i);
            s[i] = (char)(mp[x].top());
            mp[x].pop();
        }

        return s;
    }
};

int main() {
//    Solution s;
//    string str = "dcab";
//    vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};
//    const string &basicString = s.smallestStringWithSwaps(str, pairs);
//    cout << basicString << endl;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 100; ++i) {
        pq.push(i);
    }
    for (int i = 0; i < 100; ++i) {
        cout << pq.top() << "  ";
        pq.pop();
    }
    cout << endl;
    return 0;
}