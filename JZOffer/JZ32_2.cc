/**
 * @file JZ32_2 从上到下打印二叉树 II
 * @brief 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 * 思路：辅助队列 + 统计本层元素个数
 */


#include <cstdio>
#include <vector>
#include <queue>

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

        // 辅助队列
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            // 统计本层有几个元素
            int num = que.size();
            vector<int> temp{};

            // 将本层元素放入 temp 向量中
            while (num > 0) {
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                num--;
                
                // 将子节点放入队列
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }

            res.push_back(temp);
        }

        return res;
    }
};