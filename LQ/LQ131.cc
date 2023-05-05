/**
 * @file LQ131 分割回文串
 * @brief 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串
        返回 s 所有可能的分割方案。 回文串 是正着读和反着读都一样的字符串。
 *  思路：回溯算法 + 判断回文子串
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ps;
        backtrack(s, 0, path, ps);
        return ps;
    }

private:
    void backtrack(const string& str, size_t idx, vector<string>& path,
                   vector<vector<string>>& ps) {
        // 找到一组合适的分割方式
        if (idx >= str.size()) {
            ps.push_back(path);
            return;
        }

        // 遍历 str
        for (size_t i = idx; i < str.size(); ++i) {
            string temp = str.substr(idx, i - idx + 1);
            // 如果子串不是回文串，则继续添加，起到剪枝的作用
            if (isHuiWei(temp))
                path.push_back(temp);
            else
                continue;

            backtrack(str, i + 1, path, ps);
            path.pop_back();
        }
    }

    // 回文串: 相向双指针
    bool isHuiWei(string& s, int left, int right) {
        if (right < left) return false;
        while (left <= right) {
            if (s[left] != s[right]) return false;

            left++;
            right--;
        }
        return true;
    }
    // 回文串: reverse + ==
    bool isHuiWei(const string& str) {
        string temp(str);
        std::reverse(temp.begin(), temp.end());
        return temp == str;
    }
};

int main(int argc, char* argv[]) {
    string str = "aab";
    Solution so;
    vector<vector<string>> ret = so.partition(str);
    for (const auto& vec : ret) {
        for (const auto& s : vec) std::cout << s << ", ";
        std::cout << std::endl;
    }

    return 0;
}
