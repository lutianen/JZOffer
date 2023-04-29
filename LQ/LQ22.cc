/**
 * @file LQ22 括号生成
 * @brief
 * 数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。
 *
    思路：回溯
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};

        vector<string> res;
        string path;
        backTracking(path, n, n, res);
        return res;
    }

private:
    /**
     * @brief 回溯生成
     *
     * @param path 从根节点到任意节点的路径，全程只用一份
     * @param left 左括号还剩几个可以使用
     * @param right 右括号还剩几个可以使用
     * @param res 结果集
     */
    void backTracking(string& path, int left, int right, vector<string>& res) {
        // 当剩余的左、右括号都用完的时候，加入结果集
        if (left <= 0 && right <= 0) {
            res.push_back(path);
            return;
        }

        // 剪枝 - 剩余的右括号个数不可能大于剩余的左括号个数
        if (left > right) return;

        if (left > 0) {
            path.push_back('(');
            backTracking(path, left - 1, right, res);
            path.pop_back();
        }

        if (right > 0) {
            path.push_back(')');
            backTracking(path, left, right - 1, res);
            path.pop_back();
        }
    }
};

int main(int argc, char* argv[]) {
    Solution so;
    int n;
    std::cin >> n;
    vector<string> res = so.generateParenthesis(n);

    for (const auto& str : res) {
        std::cout << str << ", ";
    }
    std::cout << std::endl;
}