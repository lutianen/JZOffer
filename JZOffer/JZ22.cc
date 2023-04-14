/**
 * @file JZ22 链表中倒数第k个节点
 * @brief 输入一个链表，输出该链表中倒数第k个节点。
    为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
    例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
    链接：https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof

    思路：
        1. 缓冲 - vector
        2. 双指针 - 快慢指针
            fast 先走 k 步，然后 fast 和 cur 再同时走 n - k 步（即 fast 走到链表尾部，不用求链表长度）
 *
 */

#include <cstdio>
#include <vector>

using std::vector;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /* 对撞指针 */
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        // fast 先走 k 步
        ListNode* fast = head;
        for (int i = 0; i < k; i++) fast = fast->next;

        // 再同时走 n - k 步
        ListNode* cur = head;
        while (fast != nullptr) {
            fast = fast->next;
            cur = cur->next;
        }

        return cur;
    }

    // 缓冲
    ListNode* getKthFromEnd2(ListNode* head, int k) {
        ListNode* curr = head;
        vector<ListNode*> temp{};
        int i = 0;
        for (;;) {
            if (curr != nullptr) {
                temp.push_back(curr);
                i++;
                curr = curr->next;
            } else
                break;
        }

        return temp[i - k];
    }
};
