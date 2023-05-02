/**
 * @brief LQ206 反转链表
 *  给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */

#include <iostream>
#include <vector>

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};

ListNode* createList(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    ListNode* head = new ListNode(nodes[0]);
    ListNode* cur = head;
    for (int i = 1; i < nodes.size(); ++i) {
        cur->next = new ListNode(nodes[i]);
        cur = cur->next;
    }

    return head;
}

int main() {
    vector<int> nodes{1, 2, 3, 4, 5};
    ListNode* head = createList(nodes);
    Solution so;
    ListNode* ret = so.reverseList(head);

    return 0;
}