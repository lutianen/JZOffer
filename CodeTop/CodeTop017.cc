/**
 * @brief 二叉树的锯齿形层序遍历
 * @link https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::reverse;
using std::vector;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (nullptr == root) return {};

        vector<vector<int>> res{};
        bool L2R = true;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int k = que.size();
            vector<int> temp{};
            for (int i = 0; i < k; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);

                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }

            if (!L2R) reverse(temp.begin(), temp.end());

            res.push_back(temp);
            L2R = !L2R;
        }

        return res;
    }
};

int main() { cout << ":)" << endl; }