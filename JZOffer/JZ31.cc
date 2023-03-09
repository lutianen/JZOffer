/**
 * @file JZ31 栈的压入、弹出序列
 * @brief 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
    假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
    序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

 * 链接：https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof 

 * 思路：借用辅助栈模拟压栈、弹栈流程
 */

#include <iostream>

#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        if (pushed.empty()) return true;
        
        // 辅助栈
        stack<int> helpS {};

        // 指向弹出序列的指针
        int j = 0;
        for(int i = 0; i < pushed.size(); ++i) {
            // i -> 指向压栈序列，压入当前元素至辅助栈
            helpS.push(pushed[i]);

            // 依次判断弹出序列中元素是否与辅助栈顶元素相同
            // 若相同 -> 辅助栈弹栈，j++
            // 若不同 -> 继续向辅助栈压栈
            while (true) {
                if ((!helpS.empty()) && popped[j] == helpS.top()) {
                    helpS.pop();
                    j++;
                } else break;
            }
        }

        return helpS.empty();
    }
};

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 1, 2};

    Solution s;
    std::cout << s.validateStackSequences(pushed, popped) << std::endl;
}



