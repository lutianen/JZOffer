/**
 * @file LQ94 二叉树的中序遍历
 * @brief 给定一个二叉树的根节点root ，返回 它的中序遍历 。
 *  思路：递归遍历
 */

#include <vector>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    DFS(root, ret);

    return ret;
  }

private:
    void DFS(TreeNode* root, vector<int>& ret) {
        if (root == nullptr)
            return;

        DFS(root->left, ret);
        ret.push_back(root->val);
        DFS(root->right, ret);
    }
};