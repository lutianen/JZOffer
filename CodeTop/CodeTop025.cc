/**
 * @brief 环形链表 II
 * @link https://leetcode.cn/problems/linked-list-cycle-ii/
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (nullptr == head) return head;

        ListNode *fast = head, *slow = head;
        while(true) {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        // Don't exist cycle
        if (nullptr == fast) return nullptr;

        // Exist Cycle
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main () {
    std::cout << " list ... " << std::endl;
    return 0;
}