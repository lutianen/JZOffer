/**
 * @file LQ113 路径总和 II
 * @brief 给你二叉树的根节点 root 和一个整数目标和 targetSum，
        找出所有从根节点到叶子节点 路径总和等于给定目标和的路径。
        叶子节点 是指没有子节点的节点。

    链接：https://leetcode.cn/problems/path-sum-ii
 *
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res{};
        vector<int> path{};
        DFS(root, targetSum, res, path);
        return res;
    }

private:
    void DFS(TreeNode* root, int target, vector<vector<int>>& res,
             vector<int>& path) {
        if (root == nullptr) return;
        target -= root->val;
        path.push_back(root->val);

        // 叶子节点
        if (root->left == nullptr && root->right == nullptr && target == 0)
            res.push_back(path);

        DFS(root->left, target, res, path);
        DFS(root->right, target, res, path);
        // 回溯
        path.pop_back();
    }
};