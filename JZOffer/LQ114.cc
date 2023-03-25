/**
 * @file LQ114 二叉树展开为链表
 * @brief 给你二叉树的根结点 root ，请你将它展开为一个单链表：
        展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
        展开后的单链表应该与二叉树 先序遍历 顺序相同。

    思路：
        方法 1. 利用中序遍历将节点存放在队列中，然后用右指针串起来
        方法 2. 模拟法
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
    // in-place 解法
    void flatten2(TreeNode* root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                // 查找左子树的最右节点
                auto most_right = root->left;
                while(most_right->right != nullptr)
                    most_right = most_right->right;

                // 将右子树挂到最右节点上
                most_right->right = root->right;

                root->right = root->left;
                root->left = nullptr;
            }

            root = root->right;
        }
    }

    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        
        queue<TreeNode*> que;
        inOrder(root, que);

        root = que.front();
        que.pop();
        TreeNode* cur = root;
        while(!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            cur->right = temp;
            cur->left = nullptr;
            cur = cur->right;
        }
    }

private:
    void inOrder(TreeNode* root, queue<TreeNode*>& que) {
        if (root == nullptr)
            return;
        
        que.push(root);
        inOrder(root->left, que);
        inOrder(root->right, que);
    }

    TreeNode* helper(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* childLeft = root->left;
        TreeNode* childRight = root->right;

        if (root->left) {
            root->right = helper(childLeft);
        }
        else {
            root->right = helper(childRight);
        }

        root->left = nullptr;
        return root;
    }
};