/**
 * @file LQ876 表的中间结点
 * @brief 给你单链表的头结点 head ，请你找出并返回链表的中间结点。
        如果有两个中间结点，则返回第二个中间结点。
 *
 */

#include <iostream>
#include <vector>
#include <string>

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
    ListNode* middleNode(ListNode* head) {
        if (nullptr == head) return head;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

ListNode* createList(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    ListNode* head = new ListNode(nodes[0]);
    ListNode* cur = head;
    for (int i = 1; i < nodes.size(); ++i) {
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
    vector<int> nodes{1, 2, 3, 4};
    ListNode* head = createList(nodes);
    Solution so;
    ListNode* ret = so.middleNode(head);

    cout << ret->val << endl;
    deleteList(head);
    return 0;
}
