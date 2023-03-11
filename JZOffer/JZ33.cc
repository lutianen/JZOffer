/**
 * @file JZ33 二叉搜索树的后序遍历序列
 * @brief 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
    如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

    思路：模拟操作 - 左右中
 */


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return isPostorder(postorder, 0, postorder.size() - 1);
    }

    // 利用搜索二叉树特性：左子节点 < 根节点 < 右子节点
    // 将整个链表分段
    bool isPostorder(vector<int>& postorder, int left, int right) {
        if(left >= right) return true;
        int i = left;
        while(postorder[i] < postorder[right]) i++;
        // middle 点
        int m = i;
        while(postorder[i] > postorder[right]) i++;
        return i == right && 
            isPostorder(postorder, left, m - 1) && 
            isPostorder(postorder, m, right - 1);
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    vector<int> postorder = {1, 2, 5, 10, 9, 6, 4, 3};
    Solution s;
    std::cout << s.verifyPostorder(postorder) << std::endl;
}