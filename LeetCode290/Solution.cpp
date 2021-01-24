#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
//    vector<string> split(string s) {
//        vector<string> res;
//        string cur = "";
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] != ' ') {
//                cur += s[i];
//            } else {
//                res.push_back(cur);
//                cur = "";
//            }
//        }
//        res.push_back(cur);
//        return res;
//    }


    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        int m = str.length();
        int i = 0;
        for (auto c : pattern) {
            if (i >= m) return false;
            int j = i;
            while (j < m && str[j] != ' ') j++;
            const string &curStr = str.substr(i, j - i);
            if (map2.count(curStr) && map2[curStr] != c) {
                return false;
            }
            if (map1.count(c) && map1[c] != curStr) {
                return false;
            }
            map1[c] = curStr;
            map2[curStr] = c;
            j = i + 1;
        }
        return i >= m;
    }
};

int main() {
    Solution s;
    string str = "dog cat cat fish";
    vector<string> res = s.split(str);
    for (string s1 : res) {
        cout << s1 << endl;
    }
    return 0;
}

