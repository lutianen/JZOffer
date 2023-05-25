/**
 * @brief 相交链表
 * @link https://leetcode.cn/problems/intersection-of-two-linked-lists/
 */

#include <cstddef>
#include <iostream>
#include <ostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *cur1 = headA, *cur2 = headB;
        while (cur1 != cur2) {
            if (cur1 == nullptr)
                cur1 = headB;
            else
                cur1 = cur1->next;

            if (cur2 == nullptr)
                cur2 = headA;
            else
                cur2 = cur2->next;
        }

        return cur1 == nullptr ? nullptr : cur1;
    }
};

int main() {
    std::cout << " list ... " << std::endl;
    return 0;
}