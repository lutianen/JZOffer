/**
 * @file LQ02 两数相加
 * @brief
        给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
        请你将两个数相加，并以相同形式返回一个表示和的链表。
        你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    链接：https://leetcode.cn/problems/add-two-numbers

    思路：假设短链后面存在零结点，与长链等长；然后逐位相加，注意进位.
        int n1 = pCurr1 ? pCurr1->val : 0;
        int n2 = pCurr2 ? pCurr2->val : 0;
        int sum = n1 + n2 + count;
 */

#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (nullptr == l1) return l2;
        if (nullptr == l2) return l1;

        ListNode *cur1 = l1, *cur2 = l2;
        int count = 0;

        ListNode *head = nullptr, *cur = head;
        while (cur1 != nullptr || cur2 != nullptr) {
            int t1 = cur1 ? cur1->val : 0, t2 = cur2 ? cur2->val : 0;
            int temp = t1 + t2 + count;
            if (head == nullptr) {
                head = new ListNode(temp % 10);
                cur = head;
            } else {
                cur->next = new ListNode(temp % 10);
                cur = cur->next;
            }

            count = temp / 10;
            cur1 = cur1 ? cur1->next : cur1;
            cur2 = cur2 ? cur2->next : cur2;
        }

        if (count) cur->next = new ListNode(count);

        return head;
    }
};

ListNode* getList() {
    int t;
    vector<ListNode*> nodes;
    while (cin >> t) {
        // nodes.push_back(new ListNode(t));
        nodes.push_back(new ListNode(t));

        if (getchar() == '\n') break;
    }

    ListNode* head = nodes[0];
    ListNode* cur = head;
    for (int i = 1; i < nodes.size(); ++i) {
        cur->next = nodes[i];
        cur = cur->next;
    }

    cur->next = nullptr;
    return head;
}

void deleteList(ListNode* head) {
    if (head == nullptr) return;
    if (head->next) deleteList(head->next);
    delete head;
    head = nullptr;
}

int main() {
    /**
    9 9 9 9 9 9 9
    9 9 9 9
    */

    ListNode* l1 = getList();
    ListNode* l2 = getList();

    Solution so;
    ListNode* head = so.addTwoNumbers(l1, l2);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    deleteList(l1);
    deleteList(l2);

    return 0;
}