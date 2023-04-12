/**
 * @file JZ67 把字符串转换成整数
 * @brief 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数

    思路：拼接数字 ans = ans * 10 + (str[i] - '0');
        1. strToInt2()
            - 在每轮数字拼接前，判断 ans 在此轮拼接后是否超过 2147483647，若超过则加上符号位直接返回
            设数字拼接边界 border = 2147483647 / 10 = 214748364 ，则以下两种情况越界：
                - ans > border
                - ans = border && str[i] > '7'
        2. strToInt()
            - 逐字节判断
 */

#include <climits>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        if (str.empty()) return 0;

        bool sign = true;

        // 查找第一个非 ' ' 的位置
        int l = 0;
        while (l < str.size() && str[l] == ' ') l++;

        // 必须先判断 + -
        // 再判断是否为字母
        if (str[l] == '-') {
            sign = false;
            l++;
        } else if (str[l] == '+')
            l++;
        if (str[l] < '0' || str[l] > '9') return 0;

        // 组合结果
        int ans = 0;
        int border = INT_MAX / 10;
        for (int i = l; i < str.size(); ++i) {
            if (!std::isdigit(str[i]))
                break;

            else if (i == l)
                ans = str[i] - '0';
            else {
                // 在每轮数字拼接前，判断 ans 在此轮拼接后是否超过 2147483647，若超过则加上符号位直接返回。
                // 设数字拼接边界 border = 2147483647 / 10 = 214748364 ，则以下两种情况越界：
                // ans > border - 执行拼接10×res≥2147483650越界
                // ans = border && str[i] > '7' - 拼接后是2147483648或2147483649越界
                if (ans > border || (ans == border && str[i] > '7')) return sign ? INT_MIN : INT_MAX;

                ans = ans * 10 + (str[i] - '0');
            }
        }

        return sign ? ans : ans * -1;
    }


    // 字符串逐字节判断 - ' ', 'digit', '+-', 'alpha'
    int strToInt2(string& str) {
        if (str.empty()) return 0;

        bool sign = true;
        int cur = 0;
        while (str[cur] == ' ') cur++;

        if (str[cur] == '-') {
            sign = false;
            cur++;
        } else if (str[cur] == '+')
            cur++;

        if (!std::isdigit(str[cur])) return 0;

        long long ret = 0;
        while (cur < str.size() && std::isdigit(str[cur])) {
            char temp = str[cur++] - '0';

            ret = ret * 10 + temp;
            if (ret > INT_MAX) {
                ret = LONG_MAX;
                break;
            }
        }

        if (sign) {
            if (ret > INT_MAX) ret = INT_MAX;
        } else {
            ret = -ret;
            if (ret < INT_MIN) ret = INT_MIN;
        }

        return ret;
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    cout << s.strToInt2(str) << endl;
}