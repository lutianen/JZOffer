/**
 * @file CodeTop056.cc
 *
 * @brief 平衡二叉树
 *      给定一个二叉树，判断它是否为高度平衡的二叉树。
 *      即一个二叉树的每个节点的左右两子树的高度差的绝对值不超过 1
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
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