/**
 * @file LQ17 电话号码的字母组合
 * @brief 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按
 *      任意顺序 返回。 给出数字到字母的映射如下（与电话按键相同）。注意1不对应任何字母。

    思路：回溯
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;

        backtracking(digits, 0);
        return res;
    }

private:
    vector<string> res;
    string path;
    const string strMap[10] = {{""},    {""},    {"abc"},  {"def"}, {"ghi"},
                               {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

    void backtracking(const string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }

        const string temp = {strMap[digits[index] - '0']};
        for (int i = 0; i < temp.size(); ++i) {
            path.push_back(temp[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
};

int main() {
    string digits{"233"};
    Solution s;
    vector<string> res = s.letterCombinations(digits);

    for (auto e : res) std::cout << e << " ";
}