/**
 * @file JZ58_2 左旋转字符串
 * @brief 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能
    比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

    思路：切片 / 字符串
 */


#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    // 字符串切片
    string reverseLeftWords(string s, int n) {
        if (s.empty() || n < 0) return s;

        string temp = s.substr(0, n);
        string res = s.substr(n, s.size() - n);
        res.append(temp);
        return res;
    }


    // 字符串，即类似于自己实现切片
    string reverseLeftWords_2(string s, int n) {
        if (s.empty() || n < 0)
            return s;

        string temp;
        for (int i = 0 ; i < n; ++i) 
            temp.push_back(s[i]);

        string res;
        for (int i = n; i < s.size(); ++i)
            res.push_back(s[i]);
        
        res.append(temp);
        return res;
    }
};

int main() {
    Solution s;
    string rest = s.reverseLeftWords("abcdeff", 4);
    std::cout << rest << std::endl;

    rest = s.reverseLeftWords_2("abcdeff", 4);
    std::cout << rest << std::endl;
}