/**
 * @file JZ05.cc
 * @brief 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */


#include <iostream>
#include <string>

#include <sstream>  // stringstream

using std::string;
using std::stringstream;

class Solution {
public:

    /**
     * @brief 利用 stringstream 将 s 中的字符根据是否为 ' '，依次放入ss中; 非原地替换
     * 
     * @param s 
     * @return string 
     */
    string replaceSpace(string s) {
        if (s.size() < 0) {
            return {};
        }
        
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

    /**
     * @brief 原地替换：从后向前开始替换，利用双指针（p1 指向原子原字符串的最后，p2 指向字符数组的最后），
     * 非空格的情况下，复制 p1 至 p2；空格的情况下，p1 前移，p2 填入 %20
     * @note s.resize(s.size() + numSpace * 2)
     * @param s 
     * @return string 
     */
    string replaceBlink(string s) {
        if (s.size() < 1)
            return {};
        int p1 = s.size();

        int numSpace = 0;
        for(int i = 0; i < s.size(); ++i) 
            numSpace += (s[i] == ' ') ? 1 : 0;

        s.resize(s.size() + numSpace * 2);

        for(int i = p1 - 1, j = s.size() - 1; i < j; i--, j--) {
            if(s[i] != ' ') {
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
    Solution s;
    // string ret = s.replaceSpace("string s  adas  a     d");
    string ret = s.replaceBlink("We are happy.");

    std::cout << ret << std::endl;

    return 0;
}