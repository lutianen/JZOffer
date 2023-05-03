/**
 * @file LQ143 重排链表
 * @brief 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
            L0 → L1 → … → Ln - 1 → Ln
        请将其重新排列后变为：
            L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
        不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *  思路：
        1. 借助 deque 实现
            - 时间复杂度：O(n)
            - 空间复杂度：O(n)
 */

#include <deque>

using namespace std;

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
    // 
    void reorderList(ListNode* head) {
        if (nullptr == head) return;

        // 暂存链表结点
        deque<ListNode*> dq;
        ListNode* cur = head;
        while (nullptr != cur) {
            dq.push_back(cur);
            cur = cur->next;
        }

        // 重组
        ListNode* dummy = new ListNode(-1, nullptr);
        cur = dummy;
        while (!dq.empty()) {
            ListNode* pre = dq.front();
            dq.pop_front();

            if (!dq.empty()) {
                ListNode* nxt = dq.back();
                dq.pop_back();

                cur->next = pre;
                pre->next = nxt;
                nxt->next = nullptr;
                cur = nxt;
            } else {
                cur->next = pre;
                pre->next = nullptr;
                cur = pre;
            }
        }

        delete dummy;
    }

    void reorderList2(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid);

        while (head2->next != nullptr) {
            ListNode *nxt = head->next, *nxt2 = head2->next;
            head->next = head2;
            head2->next = nxt;
            head = nxt;
            head2 = nxt2;
        }
    }

private:
    ListNode* middleNode(ListNode* head) {
        if (nullptr == head) return head;
        ListNode *slow = head, *fast = head;
        while (true) {
            if (nullptr == fast || nullptr == fast->next) break;

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) return head;
        ListNode *pre = nullptr, *cur = head;
        while (nullptr != cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};