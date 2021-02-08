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

        vector<int> charArray1(26, 0);
        for (char &c : p) {
            charArray1[c]++;
        }

        vector<int> charArray2(26, 0);

        int L = 0, R = 0, m = p.length(), n = s.length();
        while (R <= n) {
            if (R < n && R - L + 1 <= m) {
                charArray2[s[R]]++;
                R++;
            } else {
                bool x = true;
                for (const char &c : p) {
                    if (charArray2[c] != charArray1[c]) {
                        x = false;
                        break;
                    }
                }
                if (x) {
                    res.push_back(L);
                }
                charArray2[s[L]]--;
                L++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}