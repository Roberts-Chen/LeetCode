#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> level;
        level.insert(s);
        while (res.empty()) {
            for (auto item : level) {
                if (isValid(item)) {
                    res.push_back(item);
                }
            }
            if (!res.empty()) {
                return res;
            }

            unordered_set<string> next_level;
            for (auto item : level) {
                for (int i = 0; i < item.length(); i++) {
                    if (item[i] == '(' || item[i] == ')') {
                        next_level.insert(item.substr(0, i) + item.substr(i + 1, item.length() - i - 1));
                    }
                }
            }
            level = next_level;
        }
        return res;
    }

    bool isValid(string s) {
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
    }
};

