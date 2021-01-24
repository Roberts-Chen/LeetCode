#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int n;
public:
    UnionFind(int _n) {
        n = _n;
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }


    void unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        parent[fy] = fx;
    }
};

/**
 * 解法一：并查集
 */
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();

        // 建立邮箱字符串到数字的映射关系
        unordered_map<string, int> email2num;
        int num = n;
        for (int i = 0; i < n; ++i) {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (email2num.count(accounts[i][j])) {
                    email2num[accounts[i][j]] = num;
                    ++num;
                }
            }
        }

        UnionFind unionFind(num);
        for (int i = 0; i < n; ++i) {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); ++j) {
                unionFind.unionSet(i, email2num[accounts[i][j]]);
            }
        }


        unordered_map<string, vector<string>> res;
        for (unordered_map<string, int>::iterator it = email2num.begin(); it != email2num.end(); it++) {
            int num = unionFind.find(it->second);
            res[accounts[num][0]].push_back(it->first);
        }

        vector<vector<string>> vec;
        for (auto &it : res) {
            it.second.insert(it.second.begin(), it.first);
            vec.push_back(it.second);
        }

        return vec;
    }
};

int main() {
    vector<string> strs = {"Ethan5@m.co", "Ethan0@m.co", "Ethan4@m.co"};
    sort(strs.begin(), strs.end());
    for (auto it : strs) {
        cout << it << "  ";
    }
    /*
     [["Ethan","Ethan5@m.co","Ethan0@m.co","Ethan4@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo0@m.co","Hanzo1@m.co"],["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Fern","Fern1@m.co","Fern0@m.co","Fern5@m.co"]]
     */
}
