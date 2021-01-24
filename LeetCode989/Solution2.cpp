//
// Created by 22577 on 2021/1/22.
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

/*
    解法二：将K加在数组A的末位上，然后每次只保留个位，剩下位除以10的加在数组A的前一位上
    例子：A = [1, 2, 3, 4], K = 23
    A = [1, 2, 3, 4 + 23] = [1, 2, 3, 27]，留下个位在末位，剩下的加到前一位去
    A = [1, 2, 3 + 2, 7] = [1, 2, 5, 7]正好是我们要求的答案
    A = [9, 9], K = 1
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        int n = A.size();
        vector<int> res;
        for (int i = n - 1; i >= 0 || K > 0; --i, K /= 10) {
            if (i >= 0) {
                K += A[i];
            }
            res.push_back(K % 10);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int K = 1234;
    Solution s;
    const vector<int> &form = s.addToArrayForm(nums, K);
    for (auto &it : form) {
        cout << it << "   ";
    }
    cout << endl;
    return 0;
}
