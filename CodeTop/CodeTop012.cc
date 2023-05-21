/**
 * @brief 有效的括号
 * @link https://leetcode.cn/problems/valid-parentheses
 */

#include <iostream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::string;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if (c == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                else
                    stk.pop();
            } else if (c == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                else
                    stk.pop();
            } else if (c == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                else
                    stk.pop();
            }
        }

        return stk.empty();
    }
};

int main() {
    string s("(){[]}}");
    Solution so;
    cout << so.isValid(s) << endl;
}