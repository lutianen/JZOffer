/**
 * @file JZ25 合并两个排序的链表
 * @brief 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 * 思路：3 个指针分别指向3条链表（结果链表，链表l1，链表l2），两条链表中元素逐个比较大小
 *      并插入结果链表中；不妨设l1链表较短，则结果链表接续上剩余来l2即可
 */


#include <cstdio>

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
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
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr) 
            return l1;

        ListNode* head = (l1->val > l2->val) ? l2 : l1;
        ListNode* curr = head;
        ListNode* curr1 = (l1->val > l2->val) ? l1 : l1->next;
        ListNode* curr2 = (l1->val > l2->val) ? l2->next : l2;

        // 连个链表中元素逐个比较，直至有一方为 nullptr
        while(curr1 != nullptr && curr2 != nullptr) {
            if(curr1->val > curr2->val) {
                curr->next = curr2;
                curr2 = curr2->next;
            } else{
                curr->next = curr1;
                curr1 = curr1->next;
            }

            curr = curr->next;
        }

        // 结果链表接续
        if (curr1 != nullptr)
            curr->next = curr1;
        if (curr2 != nullptr)
            curr->next = curr2;

        return head;
    }
};

