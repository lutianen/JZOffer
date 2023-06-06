/**
 * @brief 最长公共子序列
 * @link https://leetcode.cn/problems/generate-parentheses/
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::vector;
using std::string;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;

        int m = text1.size(), n = text2.size();
        // d[i][j] 表示 s1[0...i - 1] 与 s2[0...j - 1] 的最长公共子序列长度
        // d[i][j] = s1[i] == s2[j] ? d[i - 1][j - 1] + 1 : max(d[i - 1][j] or d[i][j - 1])
        // len = max(len, d[i][j])
        vector<vector<int>> d(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) d[i][0] = 0;
        for (int i = 0; i <= n; ++i) d[0][i] = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1] + 1;
                } else {
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                }
            }
        }

        return d[m][n];
    }
};

int main () {
    Solution so;

    string text1 {"abcde"};
    string text2 {"ace"};
    std::cout << so.longestCommonSubsequence(text1, text2) << std::endl;
    return 0;
}