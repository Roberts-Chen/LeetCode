#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            else if (bill == 10) {
                if (five == 0) {
                    return false;
                } else {
                    five--;
                    ten++;
                }
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> v = {5, 5, 5, 10, 5, 5, 10, 20, 20, 20};
    Solution s;
    cout << s.lemonadeChange(v) << endl;
    return 0;
}

