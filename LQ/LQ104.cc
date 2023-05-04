/**
 * @file LQ104  二叉树的最大深度
 * @brief 给定一个二叉树，找出其最大深度。
        二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
        说明: 叶子节点是指没有子节点的节点。

    思路：
        - 利用层序遍历
        - 递归实现【最优】
 */

#include <queue>

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
    // 利用递归实现，最优解
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth2(TreeNode* root) {
        int depth = 1;
        queue<TreeNode*> que;
        que.push(root);

        levelOrder(root, que, depth);

        return depth;
    }

private:
    void levelOrder(TreeNode* root, queue<TreeNode*> que, int& depth) {
        if (root == nullptr) return;

        while (!que.empty()) {
            int k = que.size();
            for (int i = 0; i < k; i++) {
                TreeNode* cur = que.front();
                que.pop();

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            depth++;
        }
    }
};