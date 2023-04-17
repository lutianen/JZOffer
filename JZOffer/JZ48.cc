/**
 * @file JZ48 最长不含重复字符的子字符串
 * @brief
 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 * 思路：
      1. 双指针 + set
      2. 动态规划
            当遇到字符串问题时，大概率需要利用 “动态规划”
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::string;
using std::vector;

class Solution {
public:
    /**
     * @brief 利用动态规划：dp[i] 表示以 s[i] 为结尾的无重复最长子串的长度
     *  dp[i] = dp[i - 1] + (s[i] in map) ? 0 : 1;
     * @param s
     * @return int
     */
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        map<char, int> strIndex;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        strIndex[s[0]] = 0;

        // 动态规划
        for (int i = 1; i < s.size(); ++i) {
            // 在哈希表中查找 s[i]
            // 未找到，dp[i] = dp[i - 1] + 1;
            if (strIndex.find(s[i]) == strIndex.end()) {
                dp[i] = dp[i - 1] + 1;
            } else {  // 找到重复字符，记录该字符位置 k
                int k = strIndex[s[i]];
                // 判断 k 是否在 dp[i - 1]区间内，如果在区间内：dp[i] = i -
                // k；否则，dp[i] = dp[i - 1] + 1;
                dp[i] = (i - k <= dp[i - 1]) ? i - k : dp[i - 1] + 1;
            }

            strIndex[s[i]] = i;
        }

        return *std::max_element(dp.begin(), dp.end());
    }

    // 双指针 + set
    int lengthOfLongestSubstring2(string s) {
        if (s.empty()) return 0;

        int L = 0, R = 0, len = 0;
        set<char> uset{};
        while (R < s.size()) {
            char cur = s[R];
            while (uset.find(cur) != uset.end()) {
                uset.erase(s[L++]);
            }

            uset.insert(cur);
            len = std::max(len, (R++) - L + 1);
        }

        return len;
    }
};

int main() {
    string s("abcabcbb");
    Solution so;
    std::cout << so.lengthOfLongestSubstring2(s);
}