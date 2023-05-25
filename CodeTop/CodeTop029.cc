/**
 * @brief 二叉树的中序遍历
 * @link https://leetcode.cn/problems/binary-tree-inorder-traversal/
 */

#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* le, TreeNode* ri) : val(v), left(le), right(ri) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec{};
        inorderTraversal(root, vec);
        return vec;
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;

        inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        inorderTraversal(root->right, vec);
    }
};

int main() {
    std::cout << " Tree .. " << std::endl;
    return 0;
}