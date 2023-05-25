/**
 * @brief 反转链表
 * @link https://leetcode.cn/problems/reverse-linked-list
 */

#include <iostream>

using std::cout;
using std::endl;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) return head;

        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};

int main() { cout << " .. " << endl; }