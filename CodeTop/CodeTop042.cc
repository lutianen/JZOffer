/**
 * @brief 括号生成
 * @link https://leetcode.cn/problems/generate-parentheses/
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};

        vector<string> res;
        string curStr;
        dfs(curStr, n, n, res);
        return res;
    }

private:
    void dfs(string& curStr, int left, int right, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(curStr);
            return;
        }

        if (left > right) return;

        if (left > 0) {
            curStr.push_back('(');
            dfs(curStr, left - 1, right, res);
            curStr.pop_back();
        }

        if (right > 0) {
            curStr.push_back(')');
            dfs(curStr, left, right - 1, res);
            curStr.pop_back();
        }
    }
};

int main () {
    Solution so;
    auto ret = so.generateParenthesis(3);
    for (const auto& str : ret)
        std::cout << str << ", ";
    std::cout << std::endl;
    return 0;
}