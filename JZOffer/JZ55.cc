/**
 * @file JZ55 叉树的深度
 * @brief 输入一棵二叉树的根节点，求该树的深度。
        从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度

    思路：
        1. 层序遍历
        2. 递归
 */

#include <algorithm>
#include <cstdio>
#include <queue>

using std::queue;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 层序遍历
    int maxDepth(TreeNode* root) {
        if (nullptr == root) return 0;
        // 队列
        queue<TreeNode*> que;
        que.push(root);
        int dep = 0;
        while (!que.empty()) {
            int k = que.size();
            for (int i = 0; i < k; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            dep++;
        }
        return dep;

        // 递归
        // return DFS(root);
    }

private:
    // 递归
    int DFS(TreeNode* curr) {
        // leaf node
        if (curr == nullptr) return 0;

        // left/right child
        int leftDep = DFS(curr->left);
        int rightDep = DFS(curr->right);

        return std::max(leftDep, rightDep) + 1;
    }
};