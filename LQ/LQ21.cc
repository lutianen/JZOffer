/**
 * @file LQ21 合并两个有序链表
 * @brief
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
 *
 * 思路：归并排序中的 merge 操作
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
    /**
     * @brief 原地修改，空间复杂度 O(1)，时间复杂度O(m + n) = O(1)
     *
     * @param list1
     * @param list2
     * @return ListNode*
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        bool f1 = list1->val < list2->val;
        ListNode* head = nullptr;
        if (f1) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* curr = head;

        // 一直合并，直至短链末尾
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // 拼接剩余长链
        curr->next = list1 ? list1 : list2;

        return head;
    }
};
