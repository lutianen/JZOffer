/**
 * @file JZ68_2 二叉树的最近公共祖先
 * @brief 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
    思路：先序遍历
        考虑通过递归对二叉树进行先序遍历，当遇到节点 p 或 q 时返回。
        从底至顶回溯，当节点, p,q 在节点 root 的异侧时，节点 root 即为最近公共祖先，则向上返回 root
 */

#include <cstddef>  // NULL

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        return root;
    }
};





