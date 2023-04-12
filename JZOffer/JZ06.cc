/**
 * @file JZ06 从尾到头打印链表
 * @brief 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）
 *  思路： 栈
 */

#include <stdio.h>

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::stack;
using std::string;
using std::vector;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @brief 首先依次取出链表中的节点的val放入栈中，然后依次从栈中取出放入数组
     * <利用栈的先入后出特性>
     * @param head
     * @return vector<int>
     */
    vector<int> reversePrint(ListNode* head) {
        if (head == nullptr) return {};

        stack<int> ret{};
        ListNode* curr = head;
        while (curr != nullptr) {
            ret.push(curr->val);
            curr = curr->next;
        }

        vector<int> retV;
        int len = ret.size();
        for (int i = 0; i < len; ++i) {
            retV.push_back(ret.top());
            ret.pop();
        }

        return retV;
    }
};

ListNode* createList(vector<int>& list) {
    if (list.empty()) return nullptr;

    ListNode* head = new ListNode(list[0]);
    ListNode* cur = head;

    for (int i = 1; i < list.size(); i++) {
        cur->next = new ListNode(list[i]);
        cur = cur->next;
    }

    return head;
}

void deleteList(ListNode* head) {
    if (head == nullptr) return;

    if (head->next != nullptr) deleteList(head->next);

    delete head;
}
void deleteList(vector<ListNode*> list) {
    while (!list.empty()) {
        delete list.back();
        list.pop_back();
    }
}

int main() {
    vector<int> list;

    int val;
    while (cin >> val) {
        list.push_back(val);
        if (getchar() == '\n') break;
    }

    ListNode* head = createList(list);
    Solution s;
    vector<int> ret = s.reversePrint(head);

    for (auto iter : ret) {
        cout << iter << ' ';
    }
}
