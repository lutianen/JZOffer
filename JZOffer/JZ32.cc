/**
 * @file JZ32 从上到下打印二叉树
 * @brief 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 * @note BFS，广度优先遍历，借助队列的先入先出特性实现
 */

#include <cstdio>
#include <queue>
#include <vector>

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
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> helperQ({root});
        TreeNode* curr = helperQ.front();
        vector<int> result;

        while(!helperQ.empty()) {
            curr = helperQ.front();
            result.push_back(curr->val);
            helperQ.pop();

            if (curr->left != nullptr)
                helperQ.push(curr->left);
            if (curr->right != nullptr)
                helperQ.push(curr->right);
        }

        return result;
    }
};

