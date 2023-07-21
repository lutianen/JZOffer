/**
 * @file CodeTop059.cc
 *
 * @brief 二叉树的直径
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <algorithm>
#include <iostream>

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        getLength(root, ans);
        return ans;
    }

private:
    int getLength(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;

        //
        int l = getLength(root->left, ans);
        int r = getLength(root->right, ans);

        // 当前的路径长度
        ans = max(ans, l + r);
        //
        return max(l, r) + 1;
    }
};

int main() {
    std::cout << " Tree .. " << std::endl;
    return 0;
}
