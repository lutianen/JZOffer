/**
 * @file LQ101 对称二叉树
 * @brief 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 */



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }

private:
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;
        
        if (left->val != right->val)
            return false;

        return helper(left->left, right->right) && helper(left->right, right->left); 
    }
};