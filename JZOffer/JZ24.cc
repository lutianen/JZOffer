/**
 * @file JZ24 反转链表
 * @brief 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

    思路：
        1. 利用几个指针
        2. 利用栈先进后出的特性实现
 */

#include <cstdio>
#include <stack>

using std::stack;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 3 根指针
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }

    // 利用 stack 的特性
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr) return head;

        // 先将链表入栈
        stack<ListNode*> stk;
        ListNode* cur = head;
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->next;
        }

        // 出栈实现链表反转
        head = stk.top();
        cur = head;
        stk.pop();
        while (!stk.empty()) {
            cur->next = stk.top();
            cur = cur->next;
            stk.pop();
        }

        // 最后一个节点的 next 置空
        cur->next = nullptr;
        return head;
    }
};