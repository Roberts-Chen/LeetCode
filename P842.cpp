#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        vector<int> cur;
        dfs(s, 0, s.size(), cur, 0, 0);
        return cur;
    }

    bool dfs(string s, int index, int len, vector<int> &cur, long long sum, int prev) {
        if (index >= len) {
            return cur.size() >= 3;
        }

        // 设置当前拆分的数为long long类型，可以判断当前拆分的数是否溢出
        long long tmp = 0;
        for (int i = index; i < len; ++i) {
            // 如果index指向的未拆分数列的第一个数为0，当拆分过这个0之后，就不应该再继续拆分了
            if (i > index && s[index] == '0') {
                break;
            }

            tmp = tmp * 10 + (s[i] - '0');
            // 超出int范围，直接退出，不再继续拆分
            if (tmp > INT_MAX) {
                break;
            }

            // 只有当已经拆分过的数大于等于2个时，才能判断前两个数的和与当前拆分出的数之间的大小
            if (cur.size() >= 2) {
                if (sum > tmp) {
                    continue;
                } else if (sum < tmp) {
                    break;
                }
            }

            cur.push_back(tmp);
            if (dfs(s, i + 1, len, cur, prev + tmp, tmp)) {
                return true;
            }
            cur.pop_back();
        }
        return false;
    }
};


int main() {
    string s = "123456579";
    Solution s1;
    vector<int> v = s1.splitIntoFibonacci(s);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}






