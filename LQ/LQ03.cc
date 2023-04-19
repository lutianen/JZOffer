/**
* @file LQ03 无重复字符的最长子串
 * @brief 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。

    思路：双指针 + set
        利用 set 存储字串元素，并统计子串长度
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;

class Solution {
public:
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
}
