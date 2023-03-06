/**
 * @file LQ21 合并两个有序链表
 * @brief 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
 *
 * 思路：归并排序中的 merge 操作
 */



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     if (list1 == nullptr) return list2;
    //     if (list2 == nullptr) return list1;
        
    //     ListNode* head = list1->val < list2->val ? new ListNode(list1->val) : new ListNode(list2->val);

    //     ListNode* curr1 = list1->val < list2->val ? list1->next : list1;
    //     ListNode* curr2 = list1->val < list2->val ? list2 : list2->next;
    //     ListNode* curr = head;

    //     while (curr1 != nullptr && curr2 != nullptr) {
    //         if (curr1->val < curr2->val) {
    //             curr->next = new ListNode(curr1->val);
    //             curr1 = curr1->next;
    //         } else {
    //             curr->next = new ListNode(curr2->val);
    //             curr2 = curr2->next;
    //         }
    //         curr = curr->next;
    //     }

    //     while (curr1 != nullptr) {
    //         curr->next = new ListNode(curr1->val);
    //         curr1 = curr1->next;
    //         curr = curr->next;
    //     }

    //     while (curr2 != nullptr) {
    //         curr->next = new ListNode(curr2->val);
    //         curr2 = curr2->next;
    //         curr = curr->next;
    //     }

    //     return head;
    // }


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
        
        ListNode* head = list1->val < list2->val ? new ListNode(list1->val) : new ListNode(list2->val);
        ListNode* curr = head;
        ListNode* curr1 = list1->val < list2->val ? list1->next : list1;
        ListNode* curr2 = list1->val < list2->val ? list2 : list2->next;

        // 一直合并，直至短链末尾
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
                curr = curr->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
                curr = curr->next;
            }
        }

        // 拼接剩余长链
        curr->next = curr1 ? curr1 : curr2;

        return head;
    }
};