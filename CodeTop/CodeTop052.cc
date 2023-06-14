/**
 * @brief 从前序与中序遍历序列构造二叉树
 * @link https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */

#include <iostream>
#include <vector>

using std::vector;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        size_t i = 0;
        for (; i < inorder.size(); ++i) {
            if (inorder[i] == val) break;
        }

        vector<int> iLeft(inorder.begin(), inorder.begin() + i);
        vector<int> iRight(inorder.begin() + i + 1, inorder.end());
        size_t n = iLeft.size();
        vector<int> pLeft(preorder.begin() + 1, preorder.begin() + n + 1);
        vector<int> pRight(preorder.begin() + n + 1, preorder.end());

        root->left = buildTree(pLeft, iLeft);
        root->right = buildTree(pRight, iRight);

        return root;
    }
};

int main() {
    std::cout << " Tree .. " << std::endl;
    return 0;
}