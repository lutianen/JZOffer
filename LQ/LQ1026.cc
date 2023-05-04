/**
 * @file LQ1026 节点与其祖先之间的最大差值
 * @brief 给定二叉树的根节点 root，找出存在于不同节点A和B之间的最大值V，
        其中 V = |A.val - B.val|，且A是B的祖先
        （如果A的任何子节点之一为B，或者A的任何子节点是B的祖先，那么我们认为A是B的祖先）
 *  思路：DFS + backtrack
 */

#include <algorithm>
#include <cmath>
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
    int maxAncestorDiff(TreeNode* root) {
        vector<int> path;
        vector<vector<int>> paths;
        dfs(root, path, paths);

        int res = INT_MIN;
        for (const auto& vec : paths) {
            res = max(res, abs(*max_element(vec.begin(), vec.end()) -
                               *min_element(vec.begin(), vec.end())));
        }

        return res;
    }

private:
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& paths) {
        if (root == nullptr) return;
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)
            paths.push_back(path);

        dfs(root->left, path, paths);
        dfs(root->right, path, paths);

        path.pop_back();
    }
};