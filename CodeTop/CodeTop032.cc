/**
 * @brief 编辑距离
 * @link https://leetcode.cn/problems/edit-distance/
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word2.empty() && word1.empty()) return 0;
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();

        int n1 = word1.size(), n2 = word2.size();

        /*
           d[i][j]，表示将 word1[0 .. i - 1] 转换成 word2[0 .. j - 1] 所使用的最少操作数
           d[0][0]，表示从 "" 变换到 "" 所使用的最少操作数，显然为 0
           d[0][j]，表示从 "" 变换到 word2[j - 1] 所使用的最少操作数，显然为 j
           d[i][0]，表示从 word1[i - 1] 变换到 "" 所使用的最少操作数，显然为 i
        */
        vector<vector<int>> d(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n2; ++i) d[0][i] = i;
        for (int i = 1; i <= n1; ++i) d[i][0] = i;

        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    d[i][j] = d[i - 1][j - 1];
                else {
                    d[i][j] = std::min(std::min(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
                }
            }
        }

        return d[n1][n2];
    }
};

int main() {
    // string word1{"horse"}, word2{"ros"};
    // string word1{"intention"}, word2{"execution"};
    string word1{"sea"}, word2{"eat"};
    Solution so;
    std::cout << so.minDistance(word1, word2) << std::endl;
    return 0;
}