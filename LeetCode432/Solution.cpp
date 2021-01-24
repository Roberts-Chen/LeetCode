#include <bits/stdc++.h>
using namespace std;

struct DLinkedNode{
    int val;
    set<string> keys;
    DLinkedNode *pre, *next;
    DLinkedNode(int v) : val(v), pre(nullptr), next(nullptr) {}
};

class AllOne {
private:
    unordered_map<string, int> map1;
    unordered_map<int, DLinkedNode*> map2;
    DLinkedNode *head;
    DLinkedNode *tail;
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = new DLinkedNode(-1);
        tail = new DLinkedNode(-1);
        head->next = tail;
        tail->pre = head;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        // 如果map1中存在该key
        if (map1.find(key) != map1.end()) {
            int num = map1[key];
            map1[key] = num + 1;
            DLinkedNode *node = map2[num];
            node->keys.erase(key);
            DLinkedNode *preNode = node->pre;
            if (preNode == head || preNode->val != num + 1) {
                DLinkedNode *newNode = new DLinkedNode(num + 1);
                newNode->next = node;
                node->pre = newNode;
                preNode->next = newNode;
                newNode->pre = preNode;
                newNode->keys.insert(key);
                map2.insert(make_pair(num + 1, newNode));
                preNode = newNode;
            } else {
                preNode->keys.insert(key);
            }
            if (node->keys.empty()) {
                preNode->next = node->next;
                node->next->pre = preNode;
                map2.erase(num);
            }
        } else {
            // 如果map1中不存在该key
//            map1.insert(make_pair(key, 1));
            map1[key] = 1;
            if (map2.find(1) == map2.end()) {
                DLinkedNode *newNode = new DLinkedNode(1);
                newNode->next = tail;
                newNode->pre = tail->pre;
                tail->pre->next = newNode;
                tail->pre = newNode;
                newNode->keys.insert(key);
                map2[1] = newNode;
            } else {
                DLinkedNode *node = map2[1];
                node->keys.insert(key);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (map1.find(key) != map1.end()) {
            int num = map1[key];
            DLinkedNode *node = map2[num];
            node->keys.erase(key);
            if (num == 1) {
                map1.erase(key);
            } else {
                map1[key] = num - 1;
                DLinkedNode *nextNode = node->next;
                if (nextNode == tail || nextNode->val != num - 1) {
                    DLinkedNode *newNode = new DLinkedNode(num - 1);
                    node->next = newNode;
                    newNode->pre = node;
                    newNode->next = nextNode;
                    nextNode->pre = newNode;
                    newNode->keys.insert(key);
                    map2[num - 1] = newNode;
                } else {
                    nextNode->keys.insert(key);
                }
            }
            if (node->keys.empty()) {
                node->pre->next = node->next;
                node->next->pre = node->pre;
                map2.erase(num);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (head->next == tail) {
            return "";
        } else {
            return *head->next->keys.begin();
        }
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (tail->pre == head) {
            return "";
        } else {
            return *tail->pre->keys.begin();
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

