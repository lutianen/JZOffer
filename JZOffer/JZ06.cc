/**
 * @file JZ06.cc
 * @brief 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）
 *
 */

#include <stack>
#include <vector>

#include <iostream>

using std::stack;
using std::vector;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
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
  vector<int> reversePrint(ListNode *head) {
    if (head == nullptr)
      return {};

    stack<int> ret{};
    ListNode *curr = head;
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

int main() {
    ListNode * head = new ListNode(0);

    ListNode* node1 = new ListNode(2);
    head->next = node1;
    ListNode* node2 = new ListNode(8);
    node1->next = node2;

    Solution s;
    vector<int> ret = s.reversePrint(head);

    for (auto iter: ret) {
        std::cout << iter << ' ';
    }

    delete node2;
    delete node1;
    delete head;    
}