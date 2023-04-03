/**
 * @file LQ72 编辑距离
 * @brief 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
        你可以对一个单词进行如下三种操作：
            插入一个字符
            删除一个字符
            替换一个字符
    链接：https://leetcode.cn/problems/edit-distance

    思路：动态规划
        d[i][j] - 表示 A 的前 i 个字符和 B 的前 j 个字符之间的编辑距离
 * 
 */


#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();

        int m = word1.size(), n = word2.size();
        vector<vector<int>> d(m + 1, vector<int>(n + 1));

        for(int i = 0; i <= m; i++ )
            d[i][0] = i;
        for (int i = 0; i <= n; i++)
            d[0][i] = i;
        

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) 
                    d[i][j] = d[i - 1][j - 1];
                else 
                    d[i][j] = min(min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
            }
        }

        return d[m][n];
    }
};