/**
 * @file JZ52 两个链表的第一个公共节点
 * @brief 输入两个链表，找出它们的第一个公共节点。
 *
 * 思路：假设存在交点，且交点位置到链表结尾长度为 M，链表头节点至交点长度分别为
        L1, L2 现在让两个指针都走 L1 + L2 + M，如果没有相遇，则表示无交点
 */

#include <cstdio>
#include <iostream>

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

        // 两根指针都走 L1 + L2
        ListNode *curA = headA, *curB = headB;
        while (curA != curB) {
            if (curA == nullptr)
                curA = headB;
            else
                curA = curA->next;

            if (curB == nullptr)
                curB = headA;
            else
                curB = curB->next;
        }

        // 如果没有交点，curA = curB = nullptr
        // 如果相交，curA = curB = 交点
        return curA;
    }
};
