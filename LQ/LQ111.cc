/**
 * @file LQ111 二叉树的最小深度
 * @brief 给定一个二叉树，找出其最小深度。
        最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
        说明：叶子节点是指没有子节点的节点。
 *  思路：
        - 当孩子结点有且仅有一个为 nullptr，需要返回对应的最小深度，不能取最小值
        - 当两个孩子结点同时为不为 nullptr，返回二者最小深度即可
        - 当两个孩子结点都为 nullptr 时，返回 0
 */

#include <algorithm>

using namespace std;

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
    // 当孩子结点有且仅有一个为nullptr，需要返回对应的最小深度，不能取最小值
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        else if (root->left == nullptr)
            return minDepth(root->right) + 1;
        else
            return minDepth(root->left) + 1;
    }
};