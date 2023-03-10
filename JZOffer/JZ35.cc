/**
 * @file JZ35 复杂链表的复制
 * @brief 请实现 copyRandomList 函数，复制一个复杂链表。
    在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null

    思路：
        1. 复制节点
        2. 复制 random 指针
        3. 重合链表拆分
 */


#include <cstdio>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;

        Node* curr = head;

        // 复制节点
        while(curr != nullptr) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        // 复制 random 指针
        curr = head;
        while(curr != nullptr) {
            if (curr->random != nullptr)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 拆分链表
        curr = head->next;
        Node *pre = head, *res = head->next;
        while (curr->next != nullptr) {
            pre->next = pre->next->next;
            curr->next = curr->next->next;
            pre = pre->next;
            curr = curr->next;
        }

        pre->next = nullptr;
        return res;
    }
};

