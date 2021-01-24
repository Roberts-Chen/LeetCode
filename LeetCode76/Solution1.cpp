#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 方法一：用两个数组分别存储小于x和大于等于x的节点，然后重新构造一条链表即可
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // 设置哑节点
        ListNode* dummy = new ListNode(-1);
        vector<int> nums, nums1;
        for (ListNode* it = head; it != nullptr; it = it->next) {
            if (it->val < x) {
                nums.push_back(it->val);
            } else {
                nums1.push_back(it->val);
            }
        }

        ListNode* p = dummy;
        for (int num : nums) {
            ListNode* node = new ListNode(num);
            p->next = node;
            p = node;
        }

        for (int num : nums1) {
            ListNode* node = new ListNode(num);
            p->next = node;
            p = node;
        }

        return dummy->next;
    }
};

