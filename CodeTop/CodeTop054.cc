/**
 *
 * @file CodeTop054.cc
 * @author Tianen Lu (tianenlu957@gmail.com)
 * @brief 二叉树的前序遍历
 *
 * @copyright Copyright (c) 2023 XXX
 * For study and research only, no reprinting
 */

#include <functional>
#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val_;
    TreeNode* left_;
    TreeNode* right_;

    TreeNode() : val_(0), left_(nullptr), right_(nullptr) {}
    TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right)
        : val_(val), left_(left), right_(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (nullptr == root) return {};
        vector<int> res{};

        std::function<void(TreeNode*)> f = [&](TreeNode* root) {
            if (root == nullptr) return;

            res.push_back(root->val_);
            f(root->left_);
            f(root->right_);
        };

        f(root);

        return res;
    }
};

int main() {
    std::cout << "Tree .. " << std::endl;
    return 0;
}