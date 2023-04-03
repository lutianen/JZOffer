/**
 * @file LQ1143 最长公共子序列
 * @brief 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列
 * 的长度。如果不存在 公共子序列 ，返回 0 。
 *  思路：二维动态规划
        d[i][j]，表示 s1[0,...,i] 与 s2[0,...,j] 的 LCS 的长度
        s1[i - 1] != s2[j - 1]:
            d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        s1[i - 1] == s2[j - 1]:
            d[i][j] = d[i - 1][j - 1] + 1;
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();

        if (m == 0 || n == 0) return 0;

        vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] != text2[j - 1])
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                else
                    d[i][j] = d[i - 1][j - 1] + 1;
            }
        }

        return d[m][n];
    }
};