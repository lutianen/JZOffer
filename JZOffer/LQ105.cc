/**
 * @file LQ105 从前序与中序遍历序列构造二叉树
 * @brief 给定两个整数数组 preorder 和 inorder，
        其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，
        请构造二叉树并返回其根节点。
 *  思路：递归
 */

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { 

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        int val = preorder[0];
        TreeNode* root = new TreeNode(val);

        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                index = i;
                break;
            }
        }

        vector<int> iLeft(inorder.begin(), inorder.begin() + index);
        vector<int> iRight(inorder.begin() + index + 1, inorder.end());
        int n = iLeft.size();

        vector<int> pLeft(preorder.begin() + 1, preorder.begin() + n + 1);
        vector<int> pRight(preorder.begin() + n + 1, preorder.end());

        root->left = buildTree(pLeft, iLeft);
        root->right = buildTree(pRight, iRight);
        return root;
    }
};