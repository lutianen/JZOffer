/**
 * @file JZ05.cc
 * @brief 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */


#include <iostream>
#include <string>

#include <sstream>

using std::string;
using std::stringstream;

class Solution {
public:

    /**
     * @brief 利用 stringstream 将 s 中的字符根据是否为 ' '，依次放入ss中
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
};

int main() {
    Solution s;
    string ret = s.replaceSpace("string s  adas  a     d");

    std::cout << ret << std::endl;

    return 0;
}