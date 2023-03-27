/**
 * @file LQ234 回文链表
 * @brief 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
        如果是，返回 true ；否则，返回 false 。
 *  思路：
        - 双端队列
        - 寻找链表中点 + 链表反转（后半段） + 双指针
 */


#include <deque>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
            
        ListNode* mid = findMiddleNode(head);
        ListNode* head2 = reverse(mid);

        while(head != nullptr && head2 != nullptr){
            if (head->val != head2->val)
                return false;
            
            head = head->next;
            head2 = head2->next;
        }

        return true;
    }

    
    ListNode* findMiddleNode(ListNode* head) {            
        ListNode* slow = head, *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
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

    bool isPalindrome2(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        deque<int> dque;
        ListNode* cur = head;

        while (true) {
            cur = cur->next;
            dque.push_back(cur->val);
            if (cur == nullptr)
                break;
        }

        while (!dque.empty()) {
            if (dque.size() == 1)
                break;
            
            if (dque.front() == dque.back()) {
                dque.pop_back();
                dque.pop_front();
            } else return false;
        }

        return true;
    }
};