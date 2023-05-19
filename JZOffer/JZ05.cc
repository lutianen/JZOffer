/**
 * @file JZ05 替换空格
 * @brief 请实现一个函数，把字符串 s 中的每个空格替换成"%20"

    思路：
        1. stringstream
        2. 原地替换 - 从后向前开始替换
            利用双指针（p1指向原子原字符串的最后，p2 指向字符数组的最后），
            非空格的情况下，复制 p1 至 p2；空格的情况下，p1 前移，p2 填入 %20
 */

#include <iostream>
#include <sstream>  // stringstream
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.size() < 0) return {};

        int length = s.size();
        stringstream ss;

        for (int i = 0; i < length; ++i) {
            char c = s.at(i);
            if (c == ' ') {
                ss << "%20";
            } else {
                ss << c;
            }
        }
        return ss.str();
    }

    string replaceBlink(string s) {
        if (s.size() < 1) return {};
        int p1 = s.size();

        int numSpace = 0;
        for (size_t i = 0; i < s.size(); ++i) numSpace += (s[i] == ' ') ? 1 : 0;

        s.resize(s.size() + numSpace * 2);

        // 当 i == j 时，表示左侧已没有空格，跳出循环
        for (int i = p1 - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            }
        }

        return s;
    }
};

int main() {
    string str;
    // 不能使用 cin
    std::getline(cin, str);

    Solution s;
    cout << s.replaceSpace(str) << endl;
    cout << s.replaceBlink(str) << endl;

    return 0;
}