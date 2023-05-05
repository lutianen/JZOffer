/**
 * @file LQ784 字母大小写全排列
 * @brief
        给定一个字符串s，通过将字符串s中的每个字母转变大小写，获得一个新的字符串。
          示例：
            输入：s = "a1b2"
            输出：["a1b2", "a1B2", "A1b2", "A1B2"]
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ps{};

        // backtrack(s, 0, ps);
        backtrack2(s, 0, ps);

        return ps;
    }

    vector<string> letterCasePermutation2(string s) {
        vector<string> ans{};
        std::function<void(int)> dfs = [&](size_t idx) {
            ans.push_back(s);
            for (size_t i = idx; i < s.size(); ++i) {
                if (std::isalpha(s[i])) {
                    s[i] ^= 32;
                    dfs(i + 1);
                    s[i] ^= 32;
                }
            }
        };
        dfs(0);
        return ans;
    }

private:
    /**
     * @brief 从输入的角度考虑
     *  回溯三问？
     *      1. 当前操作：枚举第 i 个字符，判断是否是字母，并选择改或不改
     *      2. 子问题：从下标 >= i 的字符串中继续构造新字符串
     *      3. 下一个子问题：从下标 >= i + 1 的子字符串中继续构造字符串
     */
    void backtrack(string& s, size_t idx, vector<string>& ps) {
        if (idx >= s.size()) {
            ps.push_back(s);
            return;
        }
        // 不选择此字符
        backtrack(s, idx + 1, ps);

        // 选择此字符
        if (std::isalpha(s[idx])) {
            s[idx] ^= 32;  // 当前操作
            backtrack(s, idx + 1, ps);
            s[idx] ^= 32;  // 恢复现场
        }
    }

    /**
     * @brief 从答案的角度
     *  回溯三问？
     *      1. 当前操作：枚举第 j >= i 个字符，判断是否是字母，若是则转换大小写
     *      2. 子问题：从下标 > i 的字符串中继续构造新字符串
     *      3. 下一个子问题：从下标 > j + 1 的子字符串中继续构造字符串
     */
    void backtrack2(string& s, size_t idx, vector<string>& ps) {
        ps.push_back(s);

        for (size_t i = idx; i < s.size(); ++i) {
            if (std::isalpha(s[i])) {
                s[i] ^= 32;
                backtrack2(s, i + 1, ps);
                s[i] ^= 32;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    string str = "a1b2";
    Solution so;
    vector<string> ret = so.letterCasePermutation(str);
    for (const auto& str : ret) std::cout << str << ", ";
    std::cout << std::endl;

    ret.clear();

    ret = so.letterCasePermutation2(str);
    for (const auto& str : ret) std::cout << str << ", ";
    std::cout << std::endl;
    return 0;
}