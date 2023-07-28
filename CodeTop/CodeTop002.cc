/**
 * @file CodeTop002.cc
 *
 * @brief 反转链表
 *  给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
 *
 * @link https://leetcode.cn/problems/reverse-linked-list
 *
 * @author https://github.com/lutianen
 * @copyright Copyright (c) 2023
 *  FOR STUDY AND RESEARCH SUPPORT ONLY
 */

#include <iostream>

#include "util.h"

using std::cout;
using std::endl;

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

int main() {
    vector<int> list{1, 2, 3, 4, 5};
    ListNode* head = createList(list);
    cout << dispList(head) << endl;

    Solution so;
    head = so.reverseList(head);
    cout << dispList(head) << endl;

    deleteList(head);
    return 0;
}