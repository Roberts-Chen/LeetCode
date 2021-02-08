#include <vector>
#include <iostream>

using namespace std;

/**
 * 双指针
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        int n = arr.size();
        int L = 0, R = 0, res = 1;
        while (R < n - 1) {
            if (L == R) {
                if (arr[L] == arr[L + 1]) {
                    L++;
                }
                R++;
            } else if (arr[R - 1] < arr[R] && arr[R] > arr[R + 1]) {
                R++;
            } else if (arr[R - 1] > arr[R] && arr[R] < arr[R + 1]) {
                R++;
            } else {
                L = R;
            }
            res = max(res, R - L + 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,8,4,12,4};
    int res = s.maxTurbulenceSize(nums);
    cout << res << endl;
    return 0;
}
