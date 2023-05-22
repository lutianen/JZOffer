/**
 * @brief 字符串相加
 * @link https://leetcode.cn/problems/add-strings/
 */

#include <algorithm>
#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int sn1 = num1.size(), sn2 = num2.size();
        int mn = std::max(sn1, sn2);
        if (sn1 < mn) {
            string temp;
            for (int i = 0; i < mn - sn1; ++i) temp += "0";
            num1 = temp + num1;
        } else {
            string temp;
            for (int i = 0; i < mn - sn2; ++i) temp += "0";
            num2 = temp + num2;
        }

        int count = 0;
        string res;
        for (int i = mn - 1; i >= 0; --i) {
            char v = count + (num1[i] - '0') + (num2[i] - '0');
            count = v / 10;
            res += std::to_string((v % 10));
        }
        if (count > 0)
            res += std::to_string(count);

        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main (){ 
    string num1 = "500", num2 = "9027";
    Solution so;
    std::cout << so.addStrings(num1, num2) << std::endl;
}