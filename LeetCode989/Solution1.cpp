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

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        int n = A.size();
        vector<int> res;
//        int index = A.size() - 1, carry = 0;
//        while (K != 0) {
//            int num;
//            if (index >= 0) {
//                num = A[index] + K % 10 + carry;
//                --index;
//            } else {
//                num = K % 10 + carry;
//            }
//            carry = num / 10;
//            res.push_back(num % 10);
//            K /= 10;
//        }
//        while (index >= 0) {
//            int num = A[index] + carry;
//            carry = num / 10;
//            res.push_back(num % 10);
//            --index;
//        }
//        if (carry) {
//            res.push_back(1);
//        }
//        reverse(res.begin(), res.end());

        // 用数组做先手循环，因为K如果为0之后不影响结果
        for (int i = n - 1; i >= 0; --i) {
            int sum = A[i] + K % 10;
            K /= 10;
            if (sum >= 10) {
                ++K;
                sum -= 10;
            }
            res.push_back(sum);
        }

        // 如果K还有剩余，则继续计算
        for (; K > 0; K /= 10) {
            res.push_back(K % 10);
        }

        // 反转得到正序的数组
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
