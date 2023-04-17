/**
 * @file JZ54 二叉搜索树的第k大节点
 * @brief 给定一棵二叉搜索树，请找出其中第 k 大的节点的值
 *  思路：中序遍历 + 数组
 */

#include <vector>

using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if (root == nullptr || k <= 0) return -1;

        vector<int> inOrderVec;
        inOrder(root, inOrderVec);

        return inOrderVec[inOrderVec.size() - k];
    }

    // 中序遍历
    void inOrder(TreeNode* root, vector<int>& inOrderVec) {
        if (root == nullptr) return;

        inOrder(root->left, inOrderVec);
        inOrderVec.push_back(root->val);
        inOrder(root->right, inOrderVec);
    }
};