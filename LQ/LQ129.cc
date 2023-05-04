/**
 * @file LQ129 求根节点到叶节点数字之和
 * @brief 给你一个二叉树的根节点root，树中每个节点都存放有一个0到9之间的数字。
        每条从根节点到叶节点的路径都代表一个数字：
            例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123
        计算从根节点到叶节点生成的 所有数字之和

    思路：DFS + 回溯(backtrack)
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
    int sumNumbers(TreeNode* root) {
        vector<string> res{};
        string path{};
        dfs(root, path, res);
        return getSum(res);
    }

private:
    /**
     * @brief DFS + backtrack
     */
    void dfs(TreeNode* root, string& path, vector<string>& res) {
        if (root == nullptr) return;
        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr)
            res.push_back(path);

        dfs(root->left, path, res);
        dfs(root->right, path, res);

        path.pop_back();
    }

    int getSum(const vector<string>& strs) {
        int ret = 0;
        for (const auto& str : strs) ret += stoi(str);
        return ret;
    }
};