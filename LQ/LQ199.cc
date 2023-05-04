/**
 * @file LQ199 二叉树的右视图
 * @brief 给定一个二叉树的 根节点 root，
        想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值
 *  思路：BFS
 */

#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res{};
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int k = que.size();
            for (int i = 0; i < k; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                if (i == 0) res.push_back(cur->val);
                if (cur->right != nullptr) que.push(cur->right);
                if (cur->left != nullptr) que.push(cur->left);
            }
        }

        return res;
    }
};