/**
 * @brief 合并两个有序链表
 * @link https://leetcode.cn/problems/merge-two-sorted-lists/
 */

#include <iostream>

using std::cout;
using std::endl;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (nullptr == list1) return list2;
        if (nullptr == list2) return list1;

        bool flag = list1->val < list2->val ? true : false;
        ListNode* head = nullptr;
        if (flag) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* cur = head;
        while (list1 != nullptr && list2 != nullptr) {
            flag = list1->val < list2->val ? true : false;
            if (flag) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }

            cur = cur->next;
        }
        if (list1 == nullptr) cur->next = list2;
        if (list2 == nullptr) cur->next = list1;

        return head;
    }
};

int main() {
    cout << " ... " << endl;
    return 0;
}