/**
 * @file CodeTop055.cc
 * 
 * @brief 对称二叉树
 * 
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <functional>
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        std::function<bool(TreeNode*, TreeNode*)> f = [&](TreeNode* left,
                                                          TreeNode* right) {
            if (left == nullptr && right == nullptr) return true;
            if (left == nullptr || right == nullptr) return false;

            return left->val == right->val && f(left->left, right->right) &&
                   f(left->right, right->left);
        };
        return f(root->left, root->right);
    }
};

int main() {
    std::cout << "Tree .. " << std::endl;
    return 0;
}