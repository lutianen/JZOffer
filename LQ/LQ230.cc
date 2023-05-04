/**
 * @file LQ230 二叉搜索树中第K小的元素
 * @brief 给定一个二叉搜索树的根节点 root ，和一个整数 k，
        请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
 *  思路：中序遍历
 */

#include <vector>

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
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return res;
    }

private:
    // 空间复杂度 O(N)
    int res = 0;
    void inOrder(TreeNode* root, int& k) {
        if (nullptr == root) return;
        inOrder(root->left, k);
        k--;
        if (k == 0) res = root->val;
        inOrder(root->right, k);
    }

    // 空间复杂度 O(N)
    void inOrder(TreeNode* root, vector<int>& in) {
        if (nullptr == root) return;
        inOrder(root->left, in);
        in.push_back(root->val);
        inOrder(root->right, in);
    }
};
