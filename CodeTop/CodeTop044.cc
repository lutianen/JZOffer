/**
 * @brief 字符串转换整数 (atoi)
 * @link https://leetcode.cn/problems/string-to-integer-atoi/
 */

#include <climits>
#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int myAtoi(std::string& s) {
        if (s.empty()) return 0;

        size_t cur = 0;
        while (s[cur] == ' ') ++cur;

        bool sign = true;
        if (s[cur] == '+' || s[cur] == '-') {
            sign = s[cur] == '-' ? false : true;
            ++cur;
        }

        long long res = 0;
        while (cur < s.size() && isDigit(s[cur])) {
            int num = s[cur++] - '0';

            if (res >= LONG_LONG_MAX / 10) break;
            res = res * 10 + num;
        }

        if (!sign)
            res = -res < INT_MIN ? INT_MIN : -res;
        else
            res = res > INT_MAX ? INT_MAX : res;

        return static_cast<int>(res);
    }

private:
    bool isDigit(const char c) { return c >= '0' && c <= '9'; }
};

int main() {
    Solution so;
    string s{"   -42"};
    std::cout << so.myAtoi(s) << std::endl;
}