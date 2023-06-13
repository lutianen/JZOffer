/**
 * @brief 字符串相乘
 * @link https://leetcode.cn/problems/multiply-strings/
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    // 模拟 - 每一个数字和数字字符串相乘，然后结果相加
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<string> tempVec;
        for (int i = num2.size() - 1; i >= 0; --i) {
            tempVec.push_back(intMulStr(num2[i] - '0', num1));
        }
        for (size_t i = 0; i < tempVec.size(); ++i) {
            for (int j = i; j > 0; --j) tempVec[i].push_back('0');
        }

        string res = tempVec[0];
        for (size_t i = 1; i < tempVec.size(); ++i) {
            res = addStrnumber(res, tempVec[i]);
        }
        return res;
    }

private:
    string intMulStr(int x, string& str) {
        if (x == 0) return "0";

        string strCpy = str;
        std::reverse(strCpy.begin(), strCpy.end());
        int count = 0;
        string res;

        for (const auto& c : strCpy) {
            int temp = (x * (c - '0')) + count;
            count = temp / 10;
            res.append(std::to_string(temp % 10));
        }
        if (count != 0) res.append(std::to_string(count));

        std::reverse(res.begin(), res.end());
        return res;
    }

    string addStrnumber(string& num1, string& num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        size_t n1 = num1.size(), n2 = num2.size();
        size_t len = std::max(n1, n2), count = 0;
        while (num1.size() < len) num1.push_back('0');
        while (num2.size() < len) num2.push_back('0');

        string res;
        for (size_t i = 0; i < len; ++i) {
            int temp = count + (num1[i] - '0') + (num2[i] - '0');
            res.append(std::to_string(temp % 10));
            count = temp / 10;
        }
        if (count != 0) res.append(std::to_string(count));

        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    // string num1 = "123", num2 = "456";
    string num1 = "123456789", num2 = "987654321";
    Solution so;
    std::cout << so.multiply(num1, num2) << std::endl;
    return 0;
}