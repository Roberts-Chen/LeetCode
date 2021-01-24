#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <limits>

using namespace std;

/**
 * 解法二：动态规划+最高有效位
 * 假设有一个数x：x = 762，比特位为：1011111010，其中1的个数为：7
 * 那么它和101111101（381）这个数仅有一位的差距，它们只在最低位上有所不同，x' = x / 2
 * x'和x只差一位，因为x移除最低位可以得到x'，所以res[x] = res[x'] + 1，而x' = x / 2
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i / 2] + 1;
        }
        return res;
    }
};

int main() {
    int num = 10;
    Solution s;
    const vector<int> &bits = s.countBits(num);
    for (auto item : bits) {
        cout << item << endl;
    }
    return 0;
}

