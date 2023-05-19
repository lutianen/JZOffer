/**
 * @brief 无重复字符的最长子串
 * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters
 */

#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        unordered_set<char> uset{};
        int sn = s.size();
        int left = 0, right = 0, maxLen = INT_MIN;
        while(right < sn) {
            while(uset.find(s[right]) != uset.end()) {
                uset.erase(s[left++]);
            }

            uset.insert(s[right]);
            maxLen = max(maxLen, (right++) - left + 1);
        }

        return maxLen;
    }
};

int main () {
    string s("abcabcvv");
    Solution so;
    cout << so.lengthOfLongestSubstring(s) << endl;
    return 0;
}


