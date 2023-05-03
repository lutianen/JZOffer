/**
 * @file LQ83 删除排序链表中的重复元素
 * @brief
 * 给定一个已排序的链表的头head，删除所有重复的元素，使每个元素只出现一次. 返回
 * 已排序的链表 。
 *
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head || nullptr == head->next) return head;

        ListNode *pre = head, *cur = head->next;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            // 发现重复时，cur 结点跳过，即pre不变，cur指向下一个
            if (pre->val == cur->val) {
                pre->next = nxt;
                cur->next = nullptr;
                cur = nxt;
            } else {
                pre = cur;
                cur = nxt;
            }
        }
        return head;
    }
};