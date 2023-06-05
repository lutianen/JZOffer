/**
 * @brief 两数相加
 * @link https://leetcode.cn/problems/add-two-numbers/
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(-1), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        int count = 0;
        ListNode *head = nullptr, *cur = head;

        while (true) {
            if (l1 == nullptr && l2 == nullptr) break;

            int sum = 0, rem = 0;
            if (l1 == nullptr)
                sum = count + l2->val;
            else if (l2 == nullptr)
                sum = count + l1->val;
            else
                sum = count + l1->val + l2->val;

            count = sum / 10;
            rem = sum % 10;
            if (head == nullptr) {
                head = new ListNode(rem);
                cur = head;
            } else {
                cur->next = new ListNode(rem);
                cur = cur->next;
            }
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        if (count != 0) cur->next = new ListNode(count);

        return head;
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
    vector<int> lv1{9, 9, 9, 9, 9, 9, 9};
    vector<int> lv2{9, 9, 9, 9};
    ListNode* l1 = createList(lv1);
    ListNode* l2 = createList(lv2);

    Solution so;
    ListNode* head = so.addTwoNumbers(l1, l2);
    std::cout << dispList(head) << std::endl;
}