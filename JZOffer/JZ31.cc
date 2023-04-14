/**
 * @file JZ31 栈的压入、弹出序列
 * @brief
 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
    假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
    序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2}
 就不可能是该压栈序列的弹出序列。

 * 链接：https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof

 * 思路：借用辅助栈模拟压栈、弹栈流程
 */

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
public:
    // 利用辅助栈进行模拟
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;

        // 模拟压栈、出栈操作
        stack<int> stk;
        int n = pushed.size(), k = 0;
        for (int i = 0; i < n; i++) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[k]) {
                stk.pop();
                k++;
            }
        }

        return stk.empty();
    }
};

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 1, 2};

    Solution s;
    std::cout << s.validateStackSequences(pushed, popped) << std::endl;
}
