#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkout(int n) {
        /*
            1234
            1234 % 10 = 4
            1234 / 10 = 123
            123 % 10 = 3
            123 / 10 = 12
        */
        int prev = 11;
        while (n > 0) {
            int cur = n % 10;
            if (prev < cur) return false;
            n /= 10;
            prev = cur;
        }
        return true;
    }

    int monotoneIncreasingDigits(int n) {
        vector<int> res;
        while (n > 0) {
            int cur = n % 10;
            n /= 10;
            res.push_back(cur);
        }
        int len = res.size();
        for (int i = 0; i < len - 1; ++i) {
            if (res[i] < res[i + 1]) {
                res[i + 1] -= 1;
                for (int j = 0; j <= i; ++j) {
                    res[j] = 9;
                }
            }
        }

        int tmp = 0;
        for (int i = len - 1; i >= 0; --i) {
            tmp = tmp * 10 + res[i];
        }

        return tmp;
    }
};

/**
 * 662739735
 * 662739734
 * 662739733
 *
 * @return
 */

int main() {
    Solution s;
    cout << s.monotoneIncreasingDigits(662739735) << endl;
    return 0;
}

