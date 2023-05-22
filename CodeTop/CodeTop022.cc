/**
 * @brief 反转链表 II
 * @link https://leetcode.cn/problems/reverse-linked-list-ii
 */

#include <iostream>
#include <stack>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (nullptr == head || left == right) return head;

        ListNode *dummy = new ListNode(-1, head), *p0 = dummy;
        for(int i = 0; i < left - 1; ++i) p0 = p0->next;

        ListNode *pre = nullptr, *cur = p0->next;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        p0->next->next = cur;
        p0->next = pre;

        head = dummy->next;
        delete dummy;
        dummy = nullptr;
        return head;
    }
};

int main () {
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s;
    ListNode* rHead = s.reverseBetween(head, 2, 4);
    while(rHead != nullptr) {
        std::cout << rHead->val;
        if (rHead->next != nullptr)
            std::cout << "->";
        rHead = rHead->next;
    }
    std::cout << std::endl;
}