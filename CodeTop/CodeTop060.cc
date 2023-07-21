/**
 * @file CodeTop060.cc
 *
 * @brief 验证二叉搜索树
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBST(TreeNode* root, long minv, long maxv) {
        if (root == nullptr) return true;

        long x = root->val;
        // 前序遍历
        return minv < x && x < maxv && isValidBST(root->left, minv, x) &&
               isValidBST(root->right, x, maxv);
    }
};

int main() {
    std::cout << " Tree .. " << std::endl;
    return 0;
}
