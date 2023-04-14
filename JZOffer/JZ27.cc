/**
 * @file JZ27 二叉树的镜像
 * @brief 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

    思路：
        1. 递归 - 可能出现栈溢出的情况
        2：利用辅助栈，手动维护调用栈
 */
#include <algorithm>
#include <cstdio>
#include <stack>

using std::stack;
using std::swap;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @brief 递归 - 可能会出现栈溢出的情况
     */
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;

        // 节点交换
        std::swap(root->left, root->right);

        // 递归 左子树、右子树
        mirrorTree(root->left);
        mirrorTree(root->right);

        return root;
    }

    /**
     * @brief 非递归实现 - 辅助栈(手动维护递归栈)
     */
    TreeNode* mirrorTree2(TreeNode* root) {
        if (root == nullptr) return root;

        stack<TreeNode*> stk;

        // 入栈，相当于递归第一次调用
        stk.push(root);

        while (!stk.empty()) {
            // 出栈
            TreeNode* curr = stk.top();
            stk.pop();

            // 节点交换
            swap(curr->left, curr->right);

            // 左右子节点入栈，相当于递归调用
            if (curr->left != nullptr) stk.push(curr->left);
            if (curr->right != nullptr) stk.push(curr->right);
        }

        return root;
    }
};