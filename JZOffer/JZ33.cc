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
        return DFS(postorder, 0, postorder.size() - 1);
    }

    // 利用搜索二叉树特性：左子节点 < 根节点 < 右子节点
    bool DFS(const vector<int>& postorder, int l, int r) {
        // 叶子节点
        if (l >= r) return true;

        // 查找左子树的结束位置、右子树的开始位置
        int cur = l;
        while (postorder[cur] < postorder[r]) cur++;
        int m = cur;
        while (postorder[cur] > postorder[r]) cur++;

        // 如果当前节点满足 搜索二叉树的条件，则 cur == r
        return cur == r && DFS(postorder, l, m - 1) && DFS(postorder, m, r - 1);
    }
};

int main() {
    // 在IO之前将stdio解除绑定，这样做了之后要注意不要同时混用cout和printf之类
    // 在默认的情况下cin绑定的是cout，每次执行 <<
    // 操作符的时候都要调用flush，这样会增加IO负担。
    // 可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率
    // 当遇到文件结束符（windows为ctrl+Z，unix为ctrl+D）或者无效的输入（比如用一个字符来作为一个整型数的输入时），istream的对象状态会变为无效
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    vector<int> postorder = {1, 2, 5, 10, 9, 6, 4, 3};
    Solution s;
    std::cout << s.verifyPostorder(postorder) << std::endl;
}