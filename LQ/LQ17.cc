/**
 * @file LQ17 电话号码的字母组合
 * @brief 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。
        答案可以按任意顺序返回。
        给出数字到字母的映射如下（与电话按键相同）。注意1不对应任何字母。
    思路：回溯
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ps;
        string path;
        backtracking(digits, 0, path, ps);
        return ps;
    }

private:
    const string strMap[10] = {{""},    {""},    {"abc"},  {"def"}, {"ghi"},
                               {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

    /**
     * @brief BT
     *
     * @param digits 数字集合
     * @param index 表示遍历到将要遍历 >= index 数字
     * @param path 结果
     * @param ps paths
     */
    void backtracking(const string& digits, int index, string& path,
                      vector<string>& ps) {
        if (static_cast<size_t>(index) == digits.size()) {
            ps.push_back(path);
            return;
        }

        // alphas 是本层将要遍历的子集
        string alphas = strMap[digits[index] - '0'];
        for (size_t i = 0; i < alphas.size(); ++i) {
            path.push_back(alphas[i]);
            // index + 1 表示将要遍历下一个数字
            backtracking(digits, index + 1, path, ps);
            path.pop_back();
        }
    }
};

int main() {
    string digits{"23"};
    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for (auto e : res) std::cout << e << " ";
    return 0;
}
