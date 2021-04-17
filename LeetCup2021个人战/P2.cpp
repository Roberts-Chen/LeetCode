#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int m = 10, n = 10, res = 0;
//        vector<vector<int>> nums(10, vector<int>(10));
        for (int i = 0; i < (m + 1) / 2; i++) {
            //从左到右遍历“上边”
            for (int j = i; j < n - i; j++) {
                ++res;
                if (res >= 10) res -= 9;
                if (i == xPos && j == yPos) {
                    break;
                }
//                nums[i][j] = res;
            }
            //从上到下遍历“右边”
            for (int j = i + 1; j < m - i; j++) {
                ++res;
                if (res >= 10) res -= 9;
                if (j == xPos && n - 1 - j == yPos) {
                    break;
                }
//                nums[j][n - 1 - i] = res;
            }
            //从右到左遍历“下边”
            for (int j = i + 1; j < n - i; j++) {
                ++res;
                if (res >= 10) res -= 9;
                if (m - 1 - j == xPos && n - 1 - j == yPos) {
                    break;
                }
//                nums[m - 1 - i][n - 1 - j] = res;
            }
            //从下到上遍历“左边”
            for (int j = i + 1; j < m - 1 - i; j++) {
                ++res;
                if (res >= 10) res -= 9;
                if (m - 1 - j == xPos && i == yPos) {
                    break;
                }
//                nums[m - 1 - j][i] = res;
            }
        }

//        for (int i = 0; i < 10; ++i) {
//            for (int j = 0; j < 10; ++j) {
////                printf("%d\t", nums[i][j]);
//            }
//            printf("\n");
//        }
        return res;
    }
};


int main() {
    Solution s;
    int i = s.orchestraLayout(10, 9, 9);
    cout << i << endl;
    return 0;
}
/**
 * 基于SpringCloud+阿里云OSS服务的视频网站
 */
