/**
 * @file LQ142 环形链表 II
 * @brief 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。
 * 如果链表无环，则返回 null。
 */

#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode *fast = head, *slow = head;
        while (true) {
            if (nullptr == fast || nullptr == fast->next) return nullptr;

            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }

        fast = head;
        while (true) {
            if (fast == slow) break;

            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};