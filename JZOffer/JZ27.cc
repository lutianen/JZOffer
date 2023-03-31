/**
 * @file JZ27 二叉树的镜像
 * @brief 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

    思路：递归 + 先序遍历
        交换左右节点即可

    思路2：利用 栈 或 队列
 */
#include <cstdio>
#include <algorithm>
#include <stack>

using std::stack;
using std::swap;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @brief 递归实现
     *  可能会出现栈溢出的情况 
     * @param root 
     * @return TreeNode* 
     */
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        // 节点交换
        std::swap(root->left, root->right);

        // 递归 左子树、右子树
        mirrorTree(root->left);
        mirrorTree(root->right);

        return root;
    }

    /**
     * @brief 非递归实现 - 辅助栈
     * 
     * @param root 
     * @return TreeNode* 
     */
    TreeNode* mirrorTree2(TreeNode* root) {
        if (root == nullptr)
            return root;

        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();

            if (curr->left != nullptr) stk.push(curr->left);
            if (curr->right != nullptr) stk.push(curr->right);

            swap(curr->left, curr->right);
        }

        return root;
    }
};