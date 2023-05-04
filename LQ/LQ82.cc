/**
 * @file LQ82 删除排序链表中的重复元素 II
 * @brief
 *
 给定一个已排序的链表的头head，删除原始链表中所有重复数字的节点，只留下不同的数字。
 *      返回已排序的链表 。
 *  思路：
        - 频次统计 - map
 */

#include <iostream>
#include <string>
#include <unordered_map>
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
    // 频次统计 - map
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head || nullptr == head->next) return head;

        unordered_map<int, int> valCnt;
        ListNode* cur = head;
        while (nullptr != cur) {
            valCnt[cur->val]++;
            cur = cur->next;
        }

        cur = head;
        ListNode *dummy = new ListNode(-1, nullptr), *pre = dummy;
        while (nullptr != cur) {
            if (valCnt[cur->val] > 1) {
                pre->next = nullptr;
                cur = cur->next;
            } else {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }

    // 指针
    ListNode* deleteDuplicates2(ListNode* head) {
        if (nullptr == head) return head;
        ListNode *dummy = new ListNode(-1, head), *cur = dummy;
        while (cur->next && cur->next->next) {
            int val = cur->next->val;
            if (cur->next->next->val == val) {
                while (cur->next && cur->next->val == val)
                    cur->next = cur->next->next;
            } else
                cur = cur->next;
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
    for (size_t i = 1; i < nodes.size(); ++i) {
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
    vector<int> nodes{1, 2, 2};
    ListNode* head = createList(nodes);
    Solution so;
    ListNode* ret = so.deleteDuplicates(head);

    cout << dispList(ret) << endl;
    deleteList(head);
    return 0;
}
