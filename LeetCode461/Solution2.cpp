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
 * 第二种解法，布赖恩·克尼根算法
 * 快速跳过两个1之间0的位数，通过cur&(cur-1)可以直接将数cur最右边的1变为0
 * 记录通过几次这样的运算cur变成了0，那么cur当中就有几个1，从而能够得出x和y的二进制位中
 * 有多少位是不同的。
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, cur = x ^ y;
        while (cur) {
            cur = cur & (cur - 1);
            res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    int i = s.hammingDistance(INT_MAX, 2);
    cout << i << endl;
    return 0;
}
