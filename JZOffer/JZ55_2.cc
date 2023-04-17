/**
 * @file JZ55_2 平衡二叉树
 * @brief 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
        如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树

    思路：dfs
 */

#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        return std::abs(dfs(root->left) - dfs(root->right)) <= 1 &&
               isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int dfs(TreeNode* root) {
        if (nullptr == root) return 0;

        return std::max(dfs(root->left), dfs(root->right)) + 1;
    }
};
