/**
 * @brief 二叉树的最近公共祖先
 * @link https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
 */

#include <iostream>

using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || p == root || q == root) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right != nullptr) 
            return right;
        if (left != nullptr && right == nullptr)
            return left;

        return root;
    }
};

int main () {
    cout << " .. " << endl;
    return 0;
}