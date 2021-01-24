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
 * 解法三：动态规划
 * 假设有一个数x：x = 762，比特位为：1011111010，其中1的个数为：7
 * 1011111010 - 1 = 1011111001
 * 1011111010 & 1011111001 = 1011111000
 * 将x从右到左第一个为0的位置重新设置为0，并得到新的10进制数x‘，那么res[x] = rse[x'] + 1
 * 且x' = x & (x - 1)
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i) {
            res[i] = res[i & (i - 1)] + 1;
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
