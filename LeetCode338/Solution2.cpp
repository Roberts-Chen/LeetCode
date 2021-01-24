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
 * 那么它和0011111010（250）这个数仅有一位的差距，它们只在最高位上有所不同
 * 同时观察 0~10的比特位
 * 0 = 0000 0000
 * 1 = 0000 0001
 * 2 = 0000 0010
 * 3 = 0000 0011
 * 4 = 0000 0100
 * 5 = 0000 0101
 * 6 = 0000 0110
 * 7 = 0000 0111
 * 8 = 0000 1000
 * 9 = 0000 1001
 * 10 = 0000 1010
 *
 * 可以观察到2、3的二进制可以在0、1的二进制位上加上2的二进制位来得到
 * 所以可以根据0、1、2、3来得到整个0~10范围内的所有数字的二进制位
 * 0 = 0000 0000 = 0
 * 1 = 0000 0001 = 0 + 1
 * 2 = 0000 0010 = 0 + 2
 * 3 = 0000 0011 = 1 + 2
 * 4 = 0000 0100 = 0 + 4
 * 5 = 0000 0101 = 1 + 4
 * 6 = 0000 0110 = 2 + 4
 * 7 = 0000 0111 = 3 + 4
 * 8 = 0000 1000 = 0 + 8
 * 9 = 0000 1001 = 1 + 8
 * 10 = 0000 1010 = 2 + 8
 * 11 = 0000 1011 = 3 + 8
 *
 * 100 = 0110 0100 = 36 + 64
 * 所以我们可以得到这样一个结论，一个较大的数=一个较小的数+2的次方
 * 且较大的数和较小的数只在高位相差一个为1的比特位，所以可以得到转移方程
 * f(x + b) = x + 1, b = 2^y(y >= 1, b > x)
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        int b = 1, i = 0;
        while (b <= num) {
            while (i < b && i + b <= num) {
                res[i + b] = res[i] + 1;
                ++i;
            }
            i = 0;
            b <<= 1;
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
