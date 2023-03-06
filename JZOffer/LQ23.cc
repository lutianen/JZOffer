/**
 * @file LQ23 合并K个升序链表
 * @brief 给你一个链表数组，每个链表都已经按升序排列。
    请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 思路：两两拼接（待优化）
 */


#include <vector>

using std::vector;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        ListNode* temp = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            temp = mergeTwoLists(temp, lists[i]);
        }

        return temp;
    }

private:
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