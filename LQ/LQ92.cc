/**
 * @file LQ92 反转链表 II
 * @brief 给你单链表的头指针head和两个整数left和right，其中left <= right。
        请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

    链接：https://leetcode.cn/problems/reverse-linked-list-ii
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (nullptr == head) return head;

        // p0 指向 left - 1
        ListNode *dummy = new ListNode(0, head), *p0 = dummy;
        for (int i = 0; i < left - 1; ++i) p0 = p0->next;

        // [left, right] 之间链表反转
        ListNode *pre = nullptr, *cur = p0->next;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        // 修改指向
        p0->next->next = cur;
        p0->next = pre;

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
    vector<int> nodes{1, 2, 3, 4, 5};
    ListNode* head = createList(nodes);
    Solution so;
    ListNode* ret = so.reverseBetween(head, 2, 4);

    cout << dispList(head) << endl;
    deleteList(head);
    return 0;
}
