/**
 * @file LQ102 二叉树的层序遍历
 * @brief 给你二叉树的根节点 root，返回其节点值的 层序遍历（即逐层地，从左到右访问所有节点）

 * 思路：queue + 记录当前层节点的个数（queue.size())
 */

#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> que;
        que.push(root);

        vector<vector<int>> ret;
        while (!que.empty()) {
            int k = que.size();
            vector<int> temp;
            for (int i = 0; i < k; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                // result
                temp.emplace_back(cur->val);
                // add children
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            } 
            ret.push_back(temp);
        }
        return ret;
    }
};