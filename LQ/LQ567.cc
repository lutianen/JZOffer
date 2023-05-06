/**
 * @file LQ567 字符串的排列
 * @brief 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
        如果是，返回 true ；否则，返回 false 。
        换句话说，s1 的排列之一是 s2 的 子串 。
    链接：https://leetcode.cn/problems/permutation-in-string
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string t, string s) {
        unordered_map<char, int> need, window;
        for (const char c : t) ++need[c];

        size_t left = 0, right = 0, valid = 0;
        while (right < s.size()) {
            char cur = s[right++];
            if (need.count(cur)) {
                window[cur]++;
                if (window[cur] == need[cur]) ++valid;
            }

            while (right - left >= t.size()) {
                if (need.size() == valid) return true;

                char d = s[left++];
                if (need.count(d)) {
                    if (need[d] == window[d]) --valid;
                    --window[d];
                }
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution so;
    string s = "eidabhahahah";
    string t = "ab";
    std::cout << so.checkInclusion(t, s) << std::endl;
}