#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 回溯，先求出有多少个左括号和右括号不合法，然后逐步删除这些不合法的半括号
 * 再判断括号序列是否合法
 *
 */
class Solution {
private:
    vector<string> res;
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            }
            if (s[i] == ')') {
                if (left > 0) {
                    left--;
                } else {
                    right++;
                }
            }
        }
        helper(s, left, right, 0);
        return res;
    }

    void helper(string s, int left, int right, int start) {
        if (!left && !right) {
            if (check(s)) {
                res.push_back(s);
            }
        }
        for (int i = start; i < s.length(); i++) {
            // 去重，比如(()))()中有一个不合法的')'，无论删除（2，3，4）哪一个都可以得到(())()序列，
            // 我们只选择索引位置最小的那个进行删除
            if (i > start && s[i] == s[i - 1]) {
                continue;
            }

            if (left && s[i] == '(') {
                helper(s.substr(0, i) + s.substr(i + 1, s.length() - i - 1), left - 1, right, i);
            }

            if (right && s[i] == ')') {
                helper(s.substr(0, i) + s.substr(i + 1, s.length() - i - 1), left, right - 1, i);
            }
        }
    }

    bool check(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                ans++;
            } else if (s[i] == ')') {
                if (ans > 0) {
                    ans--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};