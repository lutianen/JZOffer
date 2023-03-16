/**
 * @file LQ49 字母异位分词
 * @brief 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
        字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
        链接：https://leetcode.cn/problems/group-anagrams
 *      思路：将输入字符串进行排序作为 map 的 key，然后原始字符串作为 value；
 *          由于字母异位词排序后结果一样 -->> map<string, vector<string>>
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};

        unordered_map<string, vector<string>> ump;
        for (auto& str : strs) {
            string temp {str};
            sort(temp.begin(), temp.end());
            ump[temp].emplace_back(str);
        }

        vector<vector<string>> ret;
        for (auto it = ump.begin(); it != ump.end(); it++) {
            ret.emplace_back(it->second);
        }

        return ret;
    }
};