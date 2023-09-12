/**
 * @file JZ46 把数字翻译成字符串
 * @brief 给定一个数字，我们按照如下规则把它翻译为字符串：
    0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
    一个数字可能有多个翻译。
    请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法

    思路：动态规划
        dp[i]，表示 i 位数字翻译的方法数量
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    /**
     * @brief 有限制条件的“青蛙跳台阶”问题，利用动态规划解决
     */
    int translateNum(int num) {
        string numStr = std::to_string(num);

        if (numStr.size() < 2) return numStr.size();

        // dp[i] 表示 i 位数字的翻译种数
        vector<int> dp(numStr.size() + 1);
        dp[0] = 1;
        dp[1] = 1;

        // 根据最后两位数字有几种翻译方式确定
        // dp[i] = dp[i - 1] or dp[i - 1] + dp[i - 2]
        for (int i = 2; i <= numStr.size(); ++i) {
            if (numStr[i - 2] == '1' ||
                (numStr[i - 2] == '2' && numStr[i - 1] <= '5'))
                dp[i] = dp[i - 2] + dp[i - 1];
            else
                dp[i] = dp[i - 1];
        }

        return dp[numStr.size()];
    }
};

int main() {
    Solution s;
    std::cout << s.translateNum(121258) << std::endl;
}