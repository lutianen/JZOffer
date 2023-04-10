/**
 * @file JZ07 重建二叉树
 * @brief 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 *
    特性：
        前序：第一个元素永远是根节点 (root)
        中序：根节点(root)左边的所有元素都在根节点的左分支，右边的所有元素都在根节点的右分支
    算法思路：
        1. 通过前序确定根节点 (root)
        2. 将中序分割成 左分支(iLeft) 和 右分支(iRight)
        3. 根据分割后的中序左分支(iLeft)的数量，将前序进行分割 -> (pLeft), (pRight)
        4. 设置左右节点（即递归）
        5. 返回根节点
 */

#include <stdio.h>

#include <iostream>
#include <vector>


using std::cin;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        // 1. 确定根节点数值
        TreeNode* root = new TreeNode(preorder[0]);

        // 2. 在中序中寻找 root
        int i;
        for (i = 0; i < inorder.size(); ++i) {
            if (preorder[0] == inorder[i]) {
                break;
            }
        }
        // 进行中序的分割
        vector<int> iLeft(inorder.begin(), inorder.begin() + i);
        vector<int> iRight(inorder.begin() + i + 1, inorder.end());

        // 3. 根据分割后的中序左分支（iLeft), 进行前序的分割
        int n = iLeft.size();
        vector<int> pLeft(preorder.begin() + 1, preorder.begin() + 1 + n);
        vector<int> pRight(preorder.begin() + 1 + n, preorder.end());

        // 4. 设置左右孩子节点
        root->left = buildTree(pLeft, iLeft);
        root->right = buildTree(pRight, iRight);

        // 5. 返回根节点
        return root;
    }
};

int main() {
    vector<int> preorder;
    vector<int> inorder;

    // 每行输入至 '\n' 时，读入下一行
    int val;
    while (cin >> val) {
        preorder.push_back(val);
        if (getchar() == '\n') break;
    }
    while (cin >> val) {
        inorder.push_back(val);
        if (getchar() == '\n') break;
    }

    Solution so;
    TreeNode* root = so.buildTree(preorder, inorder);

    return 0;
}
