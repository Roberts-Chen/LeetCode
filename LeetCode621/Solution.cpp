#include <bits/stdc++.h>

using namespace std;

int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> mp;
    for (char c : tasks) {
        ++mp[c];
    }

    vector<int> nextTime, count;
    for (auto it : mp) {
        nextTime.push_back(1);
        count.push_back(it.second);
    }

    int len = tasks.size(), m = mp.size();
    int time = 0;
    for (int i = 0; i < len; ) {
        ++time;
        int best = -1;
        for (int j = 0; j < m; ++j) {
            if (count[j] && nextTime[j] <= time) {
                if (best == -1 || count[best] < count[j]) {
                    best = j;
                }
            }
        }
        if (best != -1) {
            nextTime[best] = n + time + 1;
            count[best] -= 1;
            ++i;
        }
    }


    return time;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << leastInterval(tasks, 2) << endl;
}

