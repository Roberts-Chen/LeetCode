#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stk;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > root) {
                return false;
            }

            while (!stk.empty() && postorder[i] < stk.top()) {
                root = stk.top();
                stk.pop();
            }
            stk.push(postorder[i]);
        }

        return true;
    }
};

int main() {
    vector<int> postorder = {1, 2, 3, 5, 6};
    Solution s;
    bool res = s.verifyPostorder(postorder);
    cout << res << endl;
    return 0;
}

