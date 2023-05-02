/**
 * @file LQ24 两两交换链表中的节点
 * @brief 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
 *      你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(-1, nullptr), *p = dummy, *pre = head,
                 *cur = head->next;

        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            // 交换两节点
            pre->next = nxt;
            cur->next = pre;
            p->next = cur;

            // 下一轮循环
            p = pre;
            pre = nxt;
            cur = nxt == nullptr ? nullptr : nxt->next;
        }

        head = dummy->next;
        delete dummy;

        return head;
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
    vector<int> nodes{1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = createList(nodes);
    Solution so;
    ListNode* ret = so.swapPairs(head);

    cout << dispList(ret) << endl;
    deleteList(ret);
    return 0;
}
