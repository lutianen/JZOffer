/**
 * @file JZ32_3 从上到下打印二叉树 III
 * @brief
 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
    第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

    思路：BFS （队列）
 */

#include <algorithm>
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
    vector<vector<int>> levelOrder2(TreeNode* root) {
        if (nullptr == root) return {};

        vector<vector<int>> ret{};
        queue<TreeNode*> q{};
        q.push(root);

        bool L2R = false;
        while (!q.empty()) {
            int k = q.size();
            vector<int> temp{};
            for (int i = 0; i < k; i++) {
                TreeNode* cur = q.front();
                q.pop();
                temp.push_back(cur->val);

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            if (L2R) reverse(temp.begin(), temp.end());
            ret.push_back(temp);
            L2R = !L2R;
        }

        return ret;
    }
};
