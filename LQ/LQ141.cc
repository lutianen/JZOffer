/**
 * @file LQ141 环形链表
 * @brief 给你一个链表的头节点 head ，判断链表中是否有环
 *
 *  思路：快慢指针
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
    bool hasCycle(ListNode* head) {
        if (nullptr == head || head->next == nullptr) return false;
        ListNode *slow = head, *fast = head;

        while (true) {
            if (nullptr == fast || nullptr == fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) break;
        }

        return nullptr != fast;
    }
};