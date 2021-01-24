#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 四个指针
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *prev1 = new ListNode(-1), *p = head;
        prev1->next = head;
        while (p != nullptr && p->val < x) {
            p = p->next;
            prev1 = prev1->next;
        }

        if (p == nullptr) return head;

        ListNode *prev2 = p, *q = p->next;
        while (q != nullptr) {
            if (q->val < x) {
                prev2->next = q->next;
                q->next = prev1->next;
                prev1->next = q;
                prev1 = prev1->next;
                q = prev2->next;
            } else {
                q = q->next;
                prev2 = prev2->next;
            }
        }

        return head;
    }
};

