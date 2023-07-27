/**
 * @file CodeTop061.cc
 *
 * @brief 路径总和 II
 *      给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有
 * 从根节点到叶子节点 路径总和等于给定目标和的路径
 *
 * @author Tian-en Lu >> https://github.com/lutianen
 * @copyright Copyright (c) 2023
 * For study and research only
 */

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path{};
        vector<vector<int>> res{};
        int sum = 0;

        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr) return;

            // 做出选择
            sum += root->val;
            path.push_back(root->val);

            // 叶子节点
            if (root->left == nullptr && root->right == nullptr &&
                sum == targetSum) {
                res.push_back(path);
            }

            dfs(root->left);
            dfs(root->right);
            sum -= path.back();
            path.pop_back();
        };

        dfs(root);
        return res;
    }
};

int main() {
    cout << "Tree .. " << endl;
    return 0;
}