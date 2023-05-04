/**
 * @file LQ236 二叉树的最近公共祖先
 * @brief 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 *
 */

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 越过叶子节点或 p/q == root
        if (root == nullptr || p == root || q == root) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // root 的 左右子树都不包含 p, q，返回 nullptr
        if (left == nullptr && right == nullptr) return nullptr;

        // 当 左子树或右子树的最近公共祖先为 nullptr时，返回相反侧的最近公共祖先
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        // p、q 在 root 节点的异侧时，节点 root 即为最近公共祖先
        return root;
    }
};