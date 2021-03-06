//
// Created by 22577 on 2021/1/24.
//


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
 * 第一种解法，通过异或运算比较最低位
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, cur = x ^ y;
        while (cur) {
            res += (cur & 1);
            cur >>= 1;
        }
        return res;
    }
};

/**
 * 汉明
 * @return
 */
int main() {
    Solution s;
    int i = s.hammingDistance(INT_MAX, 2);
    cout << i << endl;
    return 0;
}
