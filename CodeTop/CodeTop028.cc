/**
 * @brief 二叉树中的最大路径和
 * @link https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 */

#include <algorithm>
#include <climits>
#include <iostream>

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
    int ret = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }

private:
    int dfs(TreeNode* root) {
        if (nullptr == root) return 0;

        // 左右子树的最大路径和，必须大于零才能加入当前路径
        int left = std::max(0, dfs(root->left));
        int right = std::max(0, dfs(root->right));

        // 记录当前路径最值
        ret = std::max(ret, root->val + left + right);
        // 选择一条路径和较大的路径
        return std::max(left, right) + root->val;
    }
};

int main() {
    std::cout << " Tree ... " << std::endl;
    return 0;
}