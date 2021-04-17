#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
    int n = s.size();
    if (n == 0) {
        return "";
    }
    string res = "";
    vector<pair<int, char>> vp(26);
    for (const char &c : s) {
        vp[c - 'a'].first++;
        vp[c - 'a'].second = c;
    }
    priority_queue<pair<int, char>> pq;
    for (pair<int, char> p : vp) {
        if (p.first > 0) {
            pq.push(p);
        }
    }
    while (!pq.empty()) {
        pair<int, char> p = pq.top();
        pq.pop();
        res.push_back(p.second);
        if (!pq.empty()) {
            pair<int, char> q = pq.top();
            pq.pop();
            res.push_back(q.second);
            if (--q.first > 0) {
                pq.push(q);
            }
        }
        if (--p.first > 0) {
            pq.push(p);
        }
    }
    return res;
}

int main() {
    string s = "kkkkzrkatkwpkkkktrq";
    string res = reorganizeString(s);
    cout << res << endl;
    return 0;
}

