/**
 * @file LQ25 K 个一组反转链表
 * @brief
        给你链表的头节点head，每 k 个节点一组进行翻转，请你返回修改后的链表。
        k是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
        你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

    链接：https://leetcode.cn/problems/reverse-nodes-in-k-group
 *
 */

#include <iostream>
#include <string>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (nullptr == head) return head;

        int len = 0;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) len++;

        ListNode *dummy = new ListNode(0, head), *p = dummy;
        ListNode *pre = nullptr, *cur = head;
        for (; len >= k; len -= k) {
            for (int i = 0; i < k; ++i) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            ListNode* nxt = p->next;
            p->next->next = cur;
            p->next = pre;
            p = nxt;
        }

        return dummy->next;
    }

private:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        ListNode *dummy = new ListNode(0, head), *p = dummy;
        for (int i = 0; i < left - 1; ++i) p = p->next;

        ListNode *pre = nullptr, *cur = p->next;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        p->next->next = cur;
        p->next = pre;

        return dummy->next;
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

void deleteList(ListNode* head) {
    if (head == nullptr) return;
    head = head->next;
    deleteList(head);
    delete head;
}

string dispList(ListNode* head) {
    ListNode* cur = head;
    string str;
    while (cur != nullptr) {
        str += to_string(cur->val) + " -> ";
        cur = cur->next;
    }

    return str.substr(0, str.size() - 4);
}

int main() {
    vector<int> nodes{1, 2, 3, 4, 5, 6, 7, 9, 10};
    ListNode* head = createList(nodes);
    Solution so;
    ListNode* ret = so.reverseKGroup(head, 2);

    cout << dispList(ret) << endl;
    deleteList(ret);
    return 0;
}
