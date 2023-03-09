/**
 * @file JZ24 反转链表
 * @brief 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

    思路：迭代 或 利用栈的特性
 */


#include <cstdio>

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    #include <stack>
    class Solution {
    public:
        // * @brief 利用 stack 的特性，先将链表遍历一遍并装入，在将栈中节点取出
        // *  @note 最后一个节点的 next 不要忘记设置为 nullptr 
        // * @param head 
        // * @return ListNode*
        ListNode* reverseList(ListNode* head) {
            if(head == nullptr) 
                return nullptr;
            
            ListNode* curr = head;
            std::stack<ListNode*> temp {};

            while(curr != nullptr) {
                temp.push(curr);
                curr = curr->next;
            }

            curr = head = temp.top();
            temp.pop();
            while(!temp.empty()) {
                curr->next = temp.top();
                temp.pop();
                curr = curr->next;
            }

            // 坑点：最会一个节点的下一个节点为 nullptr
            curr->next = nullptr;

            return head;
        }  
    };
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};