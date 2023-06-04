/**
 * @brief 排序链表
 * @link https://leetcode.cn/problems/sort-list/
 */

#include <algorithm>
#include <memory>
#include <vector>

using std::sort;
using std::vector;

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;

        vector<ListNode*> vec{};
        ListNode* cur = head;
        while (nullptr != cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        sort(vec.begin(), vec.end(), [&](ListNode* pa, ListNode* pb) { return pa->val > pb->val; });

        auto iter = vec.begin();
        head = cur = *iter;
        for (++iter; iter != vec.end(); ++iter) {
            cur->next = *iter;
            cur = cur->next;
        }
        cur->next = nullptr;

        return head;
    }

    ListNode* sortList2(ListNode* head) { return mergeSort(head); }

private:
    ListNode* getMiddleNode(ListNode* head) {
        auto slow = head, fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTowList(ListNode* l1, ListNode* l2) {
        std::unique_ptr<ListNode> dummy(new ListNode());
        ListNode* cur = dummy.get();
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMiddleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);
        return mergeTowList(l1, l2);
    }
};