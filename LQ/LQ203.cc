/**
 * @file LQ203 移除链表元素
 * @brief 给你一个链表的头节点 head 和一个整数 val，
        请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *  思路：dummy + 指针
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head) return head;

        ListNode *dummy = new ListNode(-1, nullptr), *pre = dummy, *cur = head;
        while (nullptr != cur) {
            if (cur->val == val) {
                ListNode* nxt = cur->next;
                // 防止删除最后一个节点时，仍继续指向
                pre->next = nullptr;
                // 从原始链表中脱离出来，可用于delete
                cur->next = nullptr;
                cur = nxt;
            } else {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};