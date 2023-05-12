/**
 * @file LQ76 最小覆盖子串
 * @brief  给你一个字符串s、一个字符串t。返回s中涵盖t所有字符的最小子串。
            如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 *  算法思路：
        1. 当移动 right 扩大窗口，即加入字符时，应该更新哪些数据？
        2. 什么情况下，窗口应该暂停扩大，开始移动 left 缩小窗口？
        3. 当移动 left 缩小窗口，即移出字符时，应该更新哪些数据？
        4. 需要的结果应该在扩大窗口时，还是在缩小窗口时，进行更新？
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (const char c : t) ++need[c];

        size_t left = 0, right = 0, valid = 0;
        // 最小覆盖子串的起始索引、长度
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            // cur 是将移入窗口的字符
            char cur = s[right++];
            // 窗口内数据更新
            if (need.count(cur)) {
                ++window[cur];
                if (need[cur] == window[cur]) ++valid;
            }

            // 判断左侧窗口是否需要收缩
            while (valid == need.size()) {
                // 更新结果
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                // d 是将移出窗口的字符
                char d = s[left++];
                // 窗口内数据更新
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    --window[d];
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    Solution so;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    std::cout << so.minWindow(s, t) << std::endl;
}