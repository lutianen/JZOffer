/**
 * @file JZ68 二叉搜索数的最近公共祖先
 * @brief 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 */

#include <cstdlib>

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
     * @brief 根据二叉搜索数的特性，判断目标节点是否是根节点？左子树内？右子树内？
     * 
     * @param root 
     * @param p 
     * @param q 
     * @return TreeNode* 
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;

        // 目标都在右子树中
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // 目标都在左子树中
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // 根节点就是最近公共祖先
        return root;
    }
};

