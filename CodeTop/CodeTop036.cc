/**
 * @brief 二叉树的右视图
 * @link https://leetcode.cn/problems/binary-tree-right-side-view/
 */

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

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
    vector<int> rightSideView(TreeNode* root) {
        if (nullptr == root) return {};

        // Level trace
        vector<int> res{};
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int k = que.size();
            for (int i = 0; i < k; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                // 最右侧节点
                if (i == k - 1) res.push_back(cur->val);

                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
        }
        return res;
    }
};

int main() {
    cout << " Tree .. " << endl;
    return 0;
}