/**
 * @file LQ257 二叉树的所有路径
 * @brief 给你一个二叉树的根节点root，按任意顺序
        返回所有从根节点到叶子节点的路径。
 *  思路：Recursive + backtrack
 */

#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        vector<string> paths;
        dfs(root, path, paths);
        return paths;
    }

private:
    void dfs(TreeNode* root, vector<string>& path, vector<string>& paths) {
        if (root == nullptr) return;
        path.push_back(to_string(root->val));
        path.push_back("->");

        // leaf node
        if (root->left == nullptr && root->right == nullptr) {
            string temp = {};
            for (size_t i = 0; i < path.size() - 1; ++i) temp.append(path[i]);
            paths.push_back(temp);
        }

        // Recursive
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);

        // remove root->val and "->"
        for (int i = 0; i < 2; ++i) path.pop_back();
    }
};