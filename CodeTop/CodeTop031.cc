/**
 * @brief 删除链表中倒数第 N 个节点
 * @link https://leetcode.cn/problems/remove-nth-node-from-end-of-list
 */

#include <iostream>
#include <memory>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) { std::cout << __FUNCTION__ << std::endl; }

    ~ListNode() { std::cout << __FUNCTION__ << std::endl; }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;

        int len = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            ++len;
        }

        // 使用 dummy 节点，防止删除头节点导致异常
        // ListNode *dummy = new ListNode(-1, head);
        std::unique_ptr<ListNode> dummy(new ListNode(-1, head));
        // cur = dummy;
        cur = dummy.get();
        for (int i = 0; i <= len - n; ++i) {
            if (i == len - n) {
                ListNode* toDelNode = cur->next;
                cur->next = cur->next->next;

                delete toDelNode;
                toDelNode = nullptr;

                break;
            }
            cur = cur->next;
        }
        // 更正头节点，并释放申请的 dummy
        // head = dummy->next;
        // delete dummy;
        // dummy = nullptr;
        head = dummy->next;
        return head;
    }
};

void deleteList(ListNode* head) {
    if (head == nullptr) return;

    if (head->next != nullptr) deleteList(head->next);

    delete head;
}

int main() {
    Solution so;
    ListNode* head = new ListNode(1);

    ListNode* node1 = new ListNode(2);
    head->next = node1;

    ListNode* node2 = new ListNode(3);
    node1->next = node2;

    so.removeNthFromEnd(head, 1);

    deleteList(head);
}
