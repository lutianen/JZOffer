/**
 * @file LQ20 有效的括号
 * @brief 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s
 ，判断字符串是否有效。 有效字符串需满足： 左括号必须用相同类型的右括号闭合。
        左括号必须以正确的顺序闭合。
        每个右括号都有一个对应的相同类型的左括号。
 */

#include <iostream>
#include <stack>
#include <string>

using std::cin, std::cout, std::endl;
using std::stack;
using std::string;

class Solution {
public:
    // 思路：利用栈的特性（先进后出）
    bool isValid(string s) {
        if (s.size() < 2) return false;

        stack<char> st{};
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
            } else if (c == ']') {
                if (st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
            } else if (c == '}') {
                if (st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution so;
    string str;
    cin >> str;
    cout << so.isValid(str) << endl;
}