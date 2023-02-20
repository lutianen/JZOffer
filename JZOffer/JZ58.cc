/**
 * @file JZ58 翻转单词顺序
 * @brief 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
    为简单起见，标点符号和普通字母一样处理。

    例如输入字符串"I am a student. "，则输出"student. a am I"。

    - 无空格字符构成一个单词。
    - 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    - 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个

 * 思路：利用双指针，分别指向单词的头(left + 1)尾(right)，放入res
 * trim: 
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' '));
 */


#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return "";

        // 去除原始字符串头尾的空格
        trim(s);

        // 左右指针
        int left = s.size() - 1;
        int right = left;
        string res;
        while (left >= 0) {
            // 依次寻找右侧空格
            while (left >= 0 && s[left] != ' ') left--;
            // 单词插入
            res.append(s.substr(left + 1, right - left) + " ");
            // 跳过单词中间的空格
            while (left >= 0 && s[left] == ' ') left--;
            right = left;
        }

        return trim(res);
    }

private:
    string trim(string &str) {
        if (str.empty())
            return "";
        str.erase(0, (str.find_first_not_of(' ')));
        str.erase(str.find_last_not_of(' ') + 1);

        return str;
    }
};

int main() {
    Solution s;
    string res = s.reverseWords("abc def g.");
    std::cout << res << std::endl;
}