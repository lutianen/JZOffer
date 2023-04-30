/**
 * @file LQ23 合并K个升序链表
 * @brief 给你一个链表数组，每个链表都已经按升序排列。
    请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 思路：
        - 两两拼接
        - 小根堆：时间复杂度O(nlogk)，n 是所有链表中元素总和，k链表条数
            使用优先队列（堆）来存储每个链表的头结点，然后每次从堆顶取出最小值，
            加入到结果链表中，并将该链表的下一个节点加入到堆中，直到堆为空
 */

#include <queue>
#include <vector>

using std::priority_queue;
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
    // 小根堆
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> que(cmp);
        for (auto i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) que.push(lists[i]);
        }

        // 将链表中的每个节点取出来，让后放入小根堆中
        ListNode dummy(-1);
        ListNode* pre = &dummy;
        while (!que.empty()) {
            ListNode* cur = que.top();
            que.pop();

            pre->next = cur;
            pre = cur;
            if (cur->next != nullptr) que.push(cur->next);
        }

        return dummy.next;
    }

    // 两两合并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* temp = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            temp = mergeTwoLists(temp, lists[i]);
        }

        return temp;
    }

private:
    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* head = list1->val < list2->val ? new ListNode(list1->val)
                                                 : new ListNode(list2->val);
        ListNode* curr = head;
        ListNode* curr1 = list1->val < list2->val ? list1->next : list1;
        ListNode* curr2 = list1->val < list2->val ? list2 : list2->next;

        // 一直合并，直至短链末尾
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }

        // 拼接剩余长链
        curr->next = curr1 ? curr1 : curr2;

        return head;
    }
};