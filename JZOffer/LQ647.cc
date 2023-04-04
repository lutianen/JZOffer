/**
 * @file LQ647 回文子串
 * @brief 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目

    思路：动态规划
        d[i][j]，表示 s[i, ..., j] 是否是回文子串
        - j - i < 2
            一定是回文子串
        - j - i >= 2
            d[i][j] = s[i] == s[j] ? d[i + 1][j - 1] ? true : false : false;
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;

        int n = s.size();
        vector<vector<bool>> d(n, vector<bool>(n, false));

        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i < 2) {
                        cnt++;
                        d[i][j] = true;
                    } else if (d[i + 1][j - 1]) {
                        cnt++;
                        d[i][j] = true;
                    }
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
    s.countSubstrings(string("abc"));
}