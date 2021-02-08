#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> sorted(postorder.begin(), postorder.end());
        sort(sorted.begin(), sorted.end());
        int index = postorder.size() - 1;
        return helper(postorder, sorted, 0, sorted.size() - 1, index);
    }

    bool helper(vector<int>& postorder, vector<int>& sorted, int start, int end, int& index) {
        if (index < 0) {
            return true;
        }
        if (start > end) {
            return true;
        }
        int i = lower_bound(sorted.begin() + start, sorted.begin() + end + 1, postorder[index]) - sorted.begin();
        if (i == end + 1) {
            return false;
        }
        index--;
        return helper(postorder, sorted, i + 1, end, index) && helper(postorder, sorted, start, i - 1, index);
    }
};

int main() {
    vector<int> postorder = {1, 2, 3, 5, 6};
    int index = lower_bound(postorder.begin(), postorder.end(), 6) - postorder.begin();
    cout << index << endl;
    return 0;
}

