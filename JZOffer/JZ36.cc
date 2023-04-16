/**
 * @file JZ36 二叉搜索树与双向链表
 * @brief 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表
        要求不能创建任何新的节点，只能调整树中节点指针的指向。

 *  思路：利用中序遍历（左、根、右）实现，其中第一个节点就是双向链表的头节点
        1. 利用中序遍历（有序链表）将节点保存至 vector 中，然后串联起来即可
        2. 利用中序遍历，原地实现
 */

#include <cstdio>
#include <vector>

using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    /* 原地实现 */
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        inOrder(root);
        head->left = pre;
        pre->right = head;

        return head;
    }

    // 辅助空间
    Node* treeToDouList(Node* root) {
        if (root == nullptr) return nullptr;
        vector<Node*> inOrdVec{};

        inOrder(root, inOrdVec);

        int n = inOrdVec.size();
        Node* head = inOrdVec.front();
        Node* last = inOrdVec[n - 1];
        head->left = last;
        last->right = head;
        if (n == 2) {
            head->right = last;
            last->left = head;
            return head;
        }

        for (int i = 1; i < n - 1; i++) {
            Node* pre = inOrdVec[i - 1];
            Node* cur = inOrdVec[i];
            Node* nxt = inOrdVec[i + 1];
            pre->right = cur;
            cur->left = pre;
            cur->right = nxt;
            nxt->left = cur;
        }

        return head;
    }

private:
    // 上一个节点，头节点
    Node *pre, *head;
    void inOrder(Node* curr) {
        if (curr == nullptr) return;

        inOrder(curr->left);
        // 实现指针指向的转变

        if (pre != nullptr)
            pre->right = curr;
        else  // 头节点
            head = curr;

        curr->left = pre;
        pre = curr;
        inOrder(curr->right);
    }
    void inOrder(Node* root, vector<Node*>& inOrdVec) {
        if (nullptr == root) return;

        inOrder(root->left, inOrdVec);
        inOrdVec.push_back(root);
        inOrder(root->right, inOrdVec);
    }
};