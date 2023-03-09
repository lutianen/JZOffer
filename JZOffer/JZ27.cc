/**
 * @file JZ27 二叉树的镜像
 * @brief 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

    思路：递归 + 先序遍历
        交换左右节点即可
 */
#include <cstdio>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
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
};