/**
 * @brief 环形链表
 * @link https://leetcode.cn/problems/linked-list-cycle
 */

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (nullptr == head || nullptr == head->next) return false;

        ListNode *fast = head, *slow = head;
        while (true) {
            if (nullptr == fast || nullptr == fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }

        return fast != nullptr;
    }
};

int main() {
    cout << " .. " << endl;
    return 0;
}
