/**
 * @file LQ98 验证二叉搜索树
 * @brief 给你一个二叉树的根节点root，判断其是否是一个有效的二叉搜索树。
 *   有效二叉搜索树定义如下：
        节点的左子树只包含 小于 当前节点的数。
        节点的右子树只包含 大于 当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树

    思路：
        1. 利用二叉搜索树性质
        2. 中序遍历
 */

#include <climits>
#include <vector>

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

    // 利用二叉搜索树的性质
    // bool isValidBST(TreeNode* root) {
    //     return helper(root, LONG_MIN, LONG_MAX);
    // }

    // bool helper(TreeNode* root, long lower, long upper) {
    //     if (root == nullptr)
    //         return true;

    //     if (root->val < lower || root->val > upper)
    //         return false;

    //     return helper(root->left, lower, root->val) && 
    //             helper(root->right, root->val, upper);
    // }


    // 中序遍历
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inOrder(root, vec);
        
        if (vec.empty())
            return false;

        int cur = vec.back();
        vec.pop_back();

        while (!vec.empty()) {
            int temp = vec.back();
            if (temp >= cur)
                return false;
            cur = temp;
            vec.pop_back();
        }

        return true;
    }

    void inOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return ;

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
};



