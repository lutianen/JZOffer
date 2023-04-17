/**
 * @file JZ50 第一个只出现一次的字符
 * @brief 在字符串 s 中找出第一个只出现一次的字符。
        如果没有，返回一个单空格。 s 只包含小写字母。

    思路：map 统计频次
 */

#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

class Solution {
public:
    // map<char, int>
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';

        map<char, int> strCnt;
        for (auto ch : s) strCnt[ch]++;

        for (auto ch : s)
            if (strCnt[ch] == 1) return ch;

        return ' ';
    }

    // map 优化
    // map<char, int> ==>> map<char, bool>
    char firstUniqChar2(string s) {
        if (s.empty()) return ' ';

        map<char, bool> strCnt;
        for (auto ch : s)
            strCnt[ch] = strCnt.find(ch) == strCnt.end() ? true : false;

        for (auto ch : s)
            if (strCnt[ch]) return ch;

        return ' ';
    }
};

int main() {
    Solution s;
    std::cout << s.firstUniqChar("leetcode") << std::endl;
    std::cout << s.firstUniqChar2("leetcode") << std::endl;
}