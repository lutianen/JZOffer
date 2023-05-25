/**
 * @brief 重排链表
 * @link https://leetcode.cn/problems/reorder-list/
 */

#include <deque>
#include <iostream>

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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;

        std::deque<ListNode*> dq;
        ListNode* cur = head;

        while (nullptr != cur) {
            dq.push_back(cur);
            cur = cur->next;
        }

        bool flagFront = false;
        cur = dq.front();
        dq.pop_front();
        while (!dq.empty()) {
            if (flagFront) {
                cur->next = dq.front();
                dq.pop_front();
            } else {
                cur->next = dq.back();
                dq.pop_back();
            }

            flagFront = !flagFront;
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};

int main() {
    std::cout << " list .. " << std::endl;
    return 0;
}