/**
 * @file LQ237 删除链表中的节点
 * @brief 有一个单链表的 head，我们想删除它其中的一个节点 node
        给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。
        链表的所有值都是唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。

    链接：https://leetcode.cn/problems/delete-node-in-a-linked-list
 *
 */

#include <cstddef>

using namespace std;

// definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
