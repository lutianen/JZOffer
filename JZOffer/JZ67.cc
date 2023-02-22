/**
 * @file JZ67 把字符串转换成整数
 * @brief 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
 */


#include <limits.h>
#include<string>

using std::string;

class Solution {
public:
    int strToInt(string str) {
        if (str.empty())
            return 0;

        bool sign = true;

        // 查找第一个非 ' ' 的位置
        int l = 0;
        while (l < str.size() && str[l] == ' ') 
            l++;

        // 必须先判断 + - 
        // 再判断是否为字母
        if (str[l] == '-'){
            sign = false;
            l++;
        } else if (str[l] == '+') l++;
        if (str[l] < '0' || str[l] > '9')
            return 0;

        // 组合结果
        int ans = 0;
        int border = INT_MAX / 10;
        for (int i = l; i < str.size(); ++i) {
            if(!std::isdigit(str[i]))
                break;

            else if (i == l)
                ans = str[i] - '0';
            else {

                // 在每轮数字拼接前，判断 ans 在此轮拼接后是否超过 2147483647，若超过则加上符号位直接返回。
                // 设数字拼接边界 border = 2147483647 / 10 = 214748364 ，则以下两种情况越界：
                // ans > border 执行拼接10×res≥2147483650越界
                // ans = border && str[i] > '7' 情况二：拼接后是2147483648或2147483649越界
                if (ans > border || (ans == border && str[i] > '7'))
                    return sign ? INT_MIN : INT_MAX;

                ans = ans * 10 + (str[i] - '0');
            }
        }

        return sign ? ans : ans * -1 ;    
    }
};


int main() {
    Solution s;
    s.strToInt("-42");
}