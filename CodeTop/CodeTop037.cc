/**
 * @brief 删除排序链表中的重复元素 II
 * @link https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
 */

#include <iostream>
#include <memory>
#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head) return head;

        // ListNode *dummy = new ListNode(-1, head);
        std::unique_ptr<ListNode> dummy(new ListNode(-1, head));
        ListNode *pre = dummy.get(), *cur = head;
        while (nullptr != cur) {
            ListNode* nxt = cur->next;

            if (nxt != nullptr && cur->val == nxt->val) {
                while (nxt != nullptr && cur->val == nxt->val) {
                    cur = nxt;
                    nxt = nxt->next;
                }

                pre->next = nxt;
            }

            // 当前值不重复
            if (cur == pre->next) {
                pre = cur;
            } else if (cur == pre->next && nxt == nullptr) /* 当前值不重复，且位于最后一个节点 */ {
                pre->next = cur;
            }
            cur = nxt;
        }

        head = dummy->next;
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

int main() {
    vector<int> list{1, 1};
    ListNode* head = createList(list);

    Solution so;
    so.deleteDuplicates(head);
}