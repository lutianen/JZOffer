/**
 * @brief 链表中倒数第k个节点
 * @link https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr) return head;

        ListNode* cur = head;
        int len = 0;
        while (nullptr != cur) {
            cur = cur->next;
            ++len;
        }

        cur = head;
        for (int i = 0; i < len - k; ++i) cur = cur->next;

        return cur;
    }
};

ListNode* createList(vector<int>& list) {
    if (list.empty()) return nullptr;

    ListNode* head = new ListNode(list[0]);
    ListNode* cur = head;

    for (size_t i = 1; i < list.size(); i++) {
        cur->next = new ListNode(list[i]);
        cur = cur->next;
    }

    return head;
}

string dispList(ListNode* head) {
    ListNode* cur = head;
    string str;
    while (cur != nullptr) {
        str += std::to_string(cur->val) + " -> ";
        cur = cur->next;
    }

    return str.substr(0, str.size() - 4);
}

int main() {
    vector<int> lv1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* l1 = createList(lv1);
    int k = 2;

    Solution so;
    ListNode* head = so.getKthFromEnd(l1, k);
    std::cout << dispList(head) << std::endl;
}