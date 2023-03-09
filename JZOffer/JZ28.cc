/**
 * @file JZ28 对称的二叉树
 * @brief 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 */

#include <cstdio>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /// 方案 1：
    /// 不修改原来的树结构
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        return helper(root->left, root->right);
    }

    /// 方案 2：
    /// 先求得根节点左/右子树的镜像，然后在判断两个子树是否完全相同
    /// 修改了原来的树的结构
    bool isSymmetric2(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        root->right = getMirrorTree(root->right);
        return isSameTree(root->left, root->right);
    }

private:
    bool helper(TreeNode* A, TreeNode* B) {
        // leaf node
        if (A == nullptr && B == nullptr) 
            return true;

        // 两个节点中一个为nullptr，一个不为 nullptr
        if((A == nullptr && B != nullptr) || (A != nullptr && B == nullptr))
            return false;

        // val 不相等
        if (A->val != B->val)
            return false;
        
        return helper(A->left, B->right) && helper(A->right, B->left);
    }

    /// 求镜像树
    TreeNode* getMirrorTree(TreeNode* root) {
        getMirrorTree_(root);
        return root;
    }
    void getMirrorTree_(TreeNode* root) {
        if(root == nullptr)
            return;
        
        // 交换左右指针
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 递归交换
        getMirrorTree_(root->left);
        getMirrorTree_(root->right);
    }

    /// 判断两个树是否完全相同
    bool isSameTree(TreeNode* A, TreeNode* B) {
        // leaf node
        if (A == nullptr && B == nullptr)
            return true;

        // 其中有且只有一个节点为 nullptr
        if (A == nullptr || B == nullptr)
            return false;

        // 两个非 nullptr 结点，若 vla 不同，return false
        if (A->val != B->val)
            return false;

        // 递归判断 
        return isSameTree(A->left, B->left) && 
                isSameTree(A->right, B->right);
    }
};