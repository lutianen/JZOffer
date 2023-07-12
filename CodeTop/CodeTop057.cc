/**
 * @file CodeTop057.cc
 * 
 * @brief 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if (nullptr == root) return 0;

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    std::cout << "Tree .. " << std::endl;
    return 0;
}