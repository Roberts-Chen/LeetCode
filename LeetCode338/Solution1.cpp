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
 * 解法一：对每一个数字，分别求它们的比特位中1的个数
 * 时间复杂度：O(nk)，对于每一个数字我们都需要进行k次操作求出它的1的个数，k是该数字的位数
 * 空间复杂度：O(n)，需要一个数组来存储计算结果
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            int cur = i;
            while (cur) {
                res[i] += cur & 1;
                cur >>= 1;
            }
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
