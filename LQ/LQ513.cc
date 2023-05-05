/**
 * @file LQ513 找树左下角的值
 * @brief 给定一个二叉树的 根节点root，请找出该二叉树的最底层最左边节点的值。
        假设二叉树中至少有一个节点。
 *  思路：BFS
 */

#include <queue>
#include <vector>

using std::queue;
using std::vector;

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
    int findBottomLeftValue(TreeNode* root) {
        if (nullptr == root) return -1;

        queue<TreeNode*> que;
        que.push(root);
        vector<int> level;
        while (!que.empty()) {
            int k = que.size();
            // 每层进行清空，即只保存该层结点，优化空间
            vector<int> t{};
            level.swap(t);
            for (int i = 0; i < k; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                level.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }

        return level.front();
    }
};