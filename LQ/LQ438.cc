/**
 * @file LQ438 找到字符串中所有字母异位词
 * @brief 给定两个字符串 s 和
 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
        异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 *  思路：滑动窗口
        - 在字符串 s 中构造一个长度为与字符串 p
 的长度相同的滑动窗口，并在滑动中维护窗口中每种字母的数量
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n) return {};

        vector<char> sCount(26);
        vector<char> pCount(26);
        for (int i = 0; i < n; i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }

        vector<int> res;
        if (sCount == pCount) res.emplace_back(0);

        for (int i = 0; i < m - n; i++) {
            sCount[s[i] - 'a']--;
            sCount[s[i + n] - 'a']++;

            if (sCount == pCount) res.emplace_back(i + 1);
        }

        return res;
    }

    vector<int> findAnagrams2(string s, string p) {
        unordered_map<char, int> need, window;
        // 词频统计
        for (char c : p) need[c]++;

        vector<int> res{};
        int left = 0, right = 0, valid = 0, n = s.size();
        while (right < n) {
            // 窗口数据更新
            char cur = s[right++];
            if (need.count(cur)) {
                window[cur]++;
                if (window[cur] == need[cur]) ++valid;
            }

            // 判断左窗口是否需要收缩
            while (right - left >= p.size()) {
                // 记录结果，即把符合条件的起始索引放入 res
                if (valid == need.size()) res.push_back(left);

                // 窗口内数据更新
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    window[d]--;
                }
            }
        }

        return res;
    }
};