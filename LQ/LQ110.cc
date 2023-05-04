/**
 * @file LQ110 平衡二叉树
 * @brief 给定一个二叉树，判断它是否是高度平衡的二叉树。
        本题中，一棵高度平衡二叉树定义为：
            一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 *  思路：recursive
 */

#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (nullptr == root) return true;
        return 1 >= abs(getDepthOfTree(root->left) -
                        getDepthOfTree(root->right)) &&
               isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getDepthOfTree(TreeNode* root) {
        if (nullptr == root) return 0;
        return 1 + max(getDepthOfTree(root->left), getDepthOfTree(root->right));
    }
};