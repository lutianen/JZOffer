/**
 * @file LQ05 最长回文子串
 * @brief 给你一个字符串 s，找到 s 中最长的回文子串。

 思路：动态规划
    - 回文串特性：当串长小于等于 3 且首尾字符相同，则一定是回文串:
    dp[i][j] - 表示 strs[i, ..., j] 是否为回文串，且依赖于：
        dp[i][j] = strs[i] == strs[j] ? dp[i + 1][j - 1] : false;
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) dp[i][i] = true;

        int begin = 0;
        int maxLen = 1;
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n; ++i) {
                // j - i + 1 = L
                int j = i + L - 1;
                if (j >= n) break;

                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 >= maxLen) {
                    begin = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(begin, maxLen);
    }

    // 动态规划
    string longestPalindrome2(string s) {
        if (s.size() < 1) return s;

        int n = s.size();

        // d[i][j]，表示 s[i ... j] 是否为回文子串
        // d[i][j] = d[i - 1][j - 1] && s[i] == s[j] j - 1 >= 3
        // j - i < 3 ==>> d[i][j] = s[i] == s[j]
        vector<vector<bool>> d(n, vector(n, false));
        for (int i = 0; i < n; i++) d[i][i] = true;

        int len = 0, beg = 0;
        string ret;
        for (int tarL = 1; tarL <= n; tarL++) {
            for (int i = 0; i < n; i++) {
                int j = tarL + i - 1;
                if (j >= n) break;

                if (j - i < 3)
                    d[i][j] = s[i] == s[j];
                else
                    d[i][j] = d[i + 1][j - 1] && s[i] == s[j];

                if (d[i][j]) {
                    len = std::max(len, tarL);
                    // ret = s.substr(i, len);
                    beg = i;
                }
            }
        }

        // return ret;
        return s.substr(beg, len);
    }
};

int main() {
    Solution so;
    string str;
    std::cin >> str;

    std::cout << so.longestPalindrome(str) << std::endl;
    std::cout << so.longestPalindrome2(str) << std::endl;
}