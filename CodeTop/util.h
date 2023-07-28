/**
 * @file util.h
 *
 * @brief
 *
 * @author https://github.com/lutianen
 * @copyright Copyright (c) 2023
 *  FOR STUDY AND RESEARCH SUPPORT ONLY
 */

#pragma once

#include <string>
#include <vector>

using std::size_t;
using std::string;
using std::vector;

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

inline ListNode* createList(vector<int>& list) {
    if (list.empty()) return nullptr;
    ListNode* head = new ListNode(list[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < list.size(); i++) {
        cur->next = new ListNode(list[i]);
        cur = cur->next;
    }
    return head;
}

inline void deleteList(ListNode* head) {
    if (head == nullptr) return;
    if (head->next != nullptr) deleteList(head->next);
    delete head;
}

inline string dispList(ListNode* head) {
    ListNode* cur = head;
    string str;
    while (cur != nullptr) {
        str += std::to_string(cur->val) + " -> ";
        cur = cur->next;
    }

    return str.substr(0, str.size() - 4);
}