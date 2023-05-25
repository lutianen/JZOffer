/**
 * @brief 二叉树的层序遍历
 * @link https://leetcode.cn/problems/binary-tree-level-order-traversal/
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
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (nullptr == root) return {};
        vector<vector<int>> res;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int k = que.size();
            vector<int> temp;
            for (int i = 0; i < k; ++i) {
                auto cur = que.front();
                temp.push_back(cur->val);
                que.pop();

                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
            res.push_back(temp);
        }

        return res;
    }
};

int main() {
    cout << " ... " << endl;
    return 0;
}
