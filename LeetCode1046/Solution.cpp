#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // 将所有石头都加入到优先队列中
        for (int stone : stones) {
            pq.push(stone);
        }


        while (pq.size() >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) { a -= b; pq.push(a); }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    vector<int> stones = {2,7,4,1,8,1};
    Solution s;
    cout << s.lastStoneWeight(stones) << endl;
    return 0;
}

