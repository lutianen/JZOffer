/**
 * @file JZ28 对称的二叉树
        请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的

    思路：递归（前序遍历）
 */

#include <cstdio>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /** 修改了原来树的结构 */
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr ||
            (root->left == nullptr && nullptr == root->right))
            return true;

        return DFS(root->left, root->right);
    }

private:
    bool DFS(TreeNode* left, TreeNode* rigit) {
        if (nullptr == left && nullptr == rigit) return true;
        if (nullptr == left || nullptr == rigit) return false;

        return left->val == rigit->val && DFS(left->right, rigit->left) &&
               DFS(left->left, rigit->right);
    }
};