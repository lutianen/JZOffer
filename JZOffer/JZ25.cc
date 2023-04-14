/**
 * @file JZ25 合并两个排序的链表
 * @brief 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 *
    思路：3 个指针分别指向3条链表（结果链表，链表l1，链表l2），两条链表中元素逐个比较大小并插入结果链表中；
        不妨设l1链表较短，则结果链表接续上剩余来l2即可
 */

#include <cstdio>

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @brief 3 个指针分别指向3条链表（结果链表，链表l1，链表l2），两条链表中元素逐个比较大小
     *  并插入结果链表中；不妨设l1链表较短，则结果链表接续上剩余来l2即可
     * @param l1
     * @param l2
     * @return ListNode*
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = nullptr;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode* cur = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1 != nullptr) cur->next = l1;
        if (l2 != nullptr) cur->next = l2;

        return head;
    }
};
