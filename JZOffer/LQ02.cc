/**
 * @file LQ02 两数相加
 * @brief 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    链接：https://leetcode.cn/problems/add-two-numbers

    思路：假设短链后面存在零结点，与长链等长；然后逐位相加，注意进位.
        int n1 = pCurr1 ? pCurr1->val : 0;
        int n2 = pCurr2 ? pCurr2->val : 0;
        int sum = n1 + n2 + count;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;

        ListNode* pCurr1 = l1;
        ListNode* pCurr2 = l2;
        
        ListNode* pCurr = nullptr;
        ListNode* head = nullptr;
        int count = 0;
        while (pCurr1 != nullptr || pCurr2 != nullptr) {
            int n1 = pCurr1 ? pCurr1->val : 0;
            int n2 = pCurr2 ? pCurr2->val : 0;
            int sum = n1 + n2 + count;
            
            if (head == nullptr) 
                head = pCurr = new ListNode(sum % 10);
            else {
                pCurr->next = new ListNode(sum % 10);
                pCurr = pCurr->next;
            }
            
            count = sum / 10;
            pCurr1 = pCurr1 ? pCurr1->next : pCurr1;
            pCurr2 = pCurr2 ? pCurr2->next : pCurr2;
        }

        if (count) {
            pCurr->next = new ListNode(1);
        }

        return pCurr;
    }
};