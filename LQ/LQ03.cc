/**
* @file LQ03 无重复字符的最长子串
 * @brief 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。

    思路：双指针 + set
        利用 set 存储字串元素，并统计子串长度
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
    // 滑动窗口：左闭右开区间 [left, right)
    int lengthOfLongestSubstring2(string s) {
        if (s.empty()) return 0;

        int n = s.size(), res = INT_MIN;
        std::unordered_map<char, int> umap;  // 词频统计

        int left = 0, right = 0;
        while (right < n) {
            char cur = s[right++];
            umap[cur]++;
            while (umap[cur] > 1) {
                char d = s[left++];
                umap[d]--;
            }

            res = std::max(res, right - left);
        }

        return res;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_set<char> uset;
        int left = 0, maxLen = INT_MIN;
        for (int right = 0; right < s.size(); ++right) {
            // 从左向右逐个删除，直到 uset 中不存在 s[rightight]
            while (uset.find(s[right]) != uset.end()) uset.erase(s[left++]);

            uset.insert(s[right]);
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    string strs;
    cin >> strs;
    int ret = s.lengthOfLongestSubstring(strs);
    cout << ret << endl;

    ret = s.lengthOfLongestSubstring2(strs);
    cout << ret << endl;
}
