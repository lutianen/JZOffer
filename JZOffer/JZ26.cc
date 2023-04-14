/**
 * @file JZ26 树的子结构
 * @brief 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
        B是A的子结构， 即 A中有出现和B相同的结构和节点值。

    思路：先序遍历
 */

#include <cstdio>

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;

        // B 若是 A 为根节点的子树，return true
        if (isSubTree(A, B)) return true;

        // B 如果不是以 A 为根节点的子树，则继续判断 B 是否为以 A 的左右子树为根节点的子树
        if (isSubStructure(A->left, B) || isSubStructure(A->right, B)) return true;

        // 如果 B 不是以 A，A->left, A->right 为根节点的子树，return false
        return false;
    }

private:
    // 也可以认为是 DFS
    bool isSubTree(TreeNode* A, TreeNode* B) {
        // 若 B 是子树，则 B 先迭代完（nullptr），这时即为子树
        if (B == nullptr) return true;
        // 若 A 迭代完，而 B 没有迭代完，这时不是子树
        if (A == nullptr) return false;
        // 当前节点相等的情况下，继续判断 A 和 B 的左右子树
        return A->val == B->val && isSubTree(A->left, B->left) && isSubTree(A->right, B->right);
    }
};