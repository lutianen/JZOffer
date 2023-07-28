/**
 * @file CodeTop001.cc
 *
 * @brief 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度
 *
 * @link
 *   https://leetcode.cn/problems/longest-substring-without-repeating-characters
 *
 * @author https://github.com/lutianen
 * @copyright Copyright (c) 2023
 *  FOR STUDY AND RESEARCH SUPPORT ONLY
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_set<char> uset{};
        int sn = s.size();
        int left = 0, right = 0, maxLen = INT_MIN;
        while (right < sn) {
            while (uset.find(s[right]) != uset.end()) {
                uset.erase(s[left++]);
            }

            uset.insert(s[right]);
            maxLen = max(maxLen, (right++) - left + 1);
        }

        return maxLen;
    }
};

int main() {
    string s("abcabcvv");
    Solution so;
    cout << so.lengthOfLongestSubstring(s) << endl;
    return 0;
}
