/**
 * @file LQ19 删除链表的倒数第 N 个结点
 * @brief 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

    思路：双指针，快指针先走 n 步，然后再同时走到链表最后
    @note 需要一个哑节点 dummyNode
 */

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // 思路：双指针，快指针先走 n 步，然后再同时走到链表最后
    // @note 需要一个哑节点 dummyNode
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 0) return nullptr;

        ListNode* fast = head;
        for (int i = n; i > 0; --i) {
            fast = fast->next;
        }

        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* curr = dummyNode;
        while (fast != nullptr) {
            fast = fast->next;
            curr = curr->next;
        }

        curr->next = curr->next->next;
        ListNode* ret = dummyNode->next;
        delete dummyNode;

        return ret;
    }
};