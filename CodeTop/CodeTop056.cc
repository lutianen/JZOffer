/**
 *
 * @file CodeTop056.cc
 * @author Tianen Lu (tianenlu957@gmail.com)
 * @brief 平衡二叉树
 *      给定一个二叉树，判断它是否为高度平衡的二叉树。
 *      即一个二叉树的每个节点的左右两子树的高度差的绝对值不超过 1
 *
 * @copyright Copyright (c) 2023 XXX
 * For study and research only, no reprinting
 */

#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (nullptr == root) return true;

        return std::abs(getHeight(root->left) - getHeight(root->right)) <= 1 &&
               isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};

int main() {
    std::cout << "Tree .. " << std::endl;
    return 0;
}