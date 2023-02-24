/**
* @file LQ03 无重复字符的最长子串
 * @brief 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。

    思路：双指针 + set
        利用 set 存储字串元素，并统计子串长度
 */


#include <string>
#include <set>

using std::string;
using std::set;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int left = 0;
        set<char> temp {s[left]};
        int res = 1;

        for (int right = 1; right < s.size(); ++right) {
            while (temp.find(s[right]) != temp.end()) {
                temp.erase(s[left]);
                left++;
            }
            temp.insert(s[right]);
            res = std::max(res, right - left + 1);
        }

        return res;
    }
};

