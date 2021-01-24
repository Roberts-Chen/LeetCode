#include <bits/stdc++.h>
using namespace std;

/**
 * 递归方法求斐波那契数列的第n项，时间复杂度
 */
class Solution {
public:
    // 递归形式
    int fib(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution s;
    cout << s.fib(30) << endl;
    return 0;
}

