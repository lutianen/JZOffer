/**
 * @file JZ32 从上到下打印二叉树
 * @brief 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 * @note BFS，广度优先遍历，借助队列的先入先出特性实现
 */

#include <cstdio>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder2(TreeNode* root) {
        if (nullptr == root) return {};

        queue<TreeNode*> que{};
        vector<int> ret{};
        que.push(root);

        while (!que.empty()) {
            // 统计当前层节点的个数，通用性更高
            int k = que.size();
            for (int i = 0; i < k; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                ret.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }

        return ret;
    }
};
