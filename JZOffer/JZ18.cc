/**
 * @file JZ18 删除链表的节点
 * @brief
    给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
    说明： 题目保证链表中节点的值互不相同
          若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

    思路：双指针 - pre, cur
 */

#include <cstdio>

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr) return head;

        if (head->val == val)
            return head->next;

        ListNode* pre = head;
        ListNode* cur = head->next;

        // 使用 cur != nullptr ，而不是用 true -> 防止 val 不在链表中导致死循环
        while (cur != nullptr) {
            // 找到，跳过当前节点，退出循环
            if (cur->val == val) {
                pre->next = cur->next;
                break;
            }

            pre = pre->next;
            cur = cur->next;
        }

        return head;
    }
};
