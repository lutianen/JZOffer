/**
 * @file JZ32_3 从上到下打印二叉树 III
 * @brief 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
    第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

    思路：BFS （队列）
 */

#include <cstdio>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>

using std::vector;
using std::queue;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res {};
        if (root == nullptr) return res;

        bool LR = false;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int k = que.size();
            vector<int> temp;
            while (k > 0) {
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                k--;
                
                // 将子节点放入队列
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            if (LR) {
                std::reverse(temp.begin(), temp.end());
                LR = false;
            } else LR = true;
            res.push_back(temp);
            temp.clear();
        }

        return res;
    }
};