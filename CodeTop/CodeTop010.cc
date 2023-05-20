/**
 * @brief 最长回文子串
 * @link https://leetcode.cn/problems/longest-palindromic-substring/
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() < 2) return s;

        // stIdx - 回文串的起始下标
        int n = s.size(), stIdx = 0, len = 1;
        // d[i][j]，表示s[i ... j]是否是回文子串
        std::vector<std::vector<bool>> d(n, std::vector<bool>(n));
        d[0][0] = true;
        
        // 动态规划
        for (int r = 1; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                // d[l][r] = s[l] == s[r] && (r - l <= 2 || d[l + 1][r - 1])
                if (s[l] == s[r] && (r - l <= 2 || d[l + 1][r - 1])) {
                    d[l][r] = true;
                    // update len
                    if (r - l + 1 > len) {
                        len = r - l + 1;
                        stIdx = l;
                    }
                }
            }
        }

        return s.substr(stIdx, len);
    }
};

int main () {
    Solution so;
    string s = "abacc";
    cout << so.longestPalindrome(s) << endl;
    
    return 0;
}