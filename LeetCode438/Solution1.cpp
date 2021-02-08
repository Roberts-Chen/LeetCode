#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length()) {
            return res;
        }

        unordered_map<char, int> mp1;
        for (char &c : p) {
            mp1[c]++;
        }

        unordered_map<char, int> mp2;

        int L = 0, R = 0, m = p.length(), n = s.length();
        while (R <= n) {
            if (R < n && R - L + 1 <= m) {
                mp2[s[R]]++;
                R++;
            } else {
                bool x = true;
                for (auto it : mp1) {
                    if (mp2[it.first] != it.second) {
                        x = false;
                        break;
                    }
                }
                if (x) {
                    res.push_back(L);
                }
                mp2[s[L]]--;
                L++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}