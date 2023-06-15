/**
 * @brief 反转字符串中的单词
 * @link https://leetcode.cn/problems/reverse-words-in-a-string/
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";

        size_t cur = 0;
        while (cur < s.size() && s[cur] == ' ') ++cur;

        size_t st = cur;
        // vector<string> strs;

        stack<string> stk;
        string ret;
        while (cur < s.size()) {
            while (cur < s.size() && s[cur] != ' ') cur++;
            // strs.push_back(s.substr(st, cur - st));
            stk.push(s.substr(st, cur - st));

            while (cur < s.size() && s[cur] == ' ') ++cur;
            st = cur;
        }

        // std::reverse(strs.begin(), strs.end());
        // auto iter = strs.begin();
        // string ret = *iter;
        // for (++iter; iter != strs.end(); ++iter) ret += " " + *iter;

        ret += stk.top();
        stk.pop();
        while (!stk.empty()) {
            ret += " " + stk.top();
            stk.pop();
        }
        return ret;
    }
};

int main() {
    Solution so;
    // string s = "  hello world cpp ";
    // string s = "the sky is blue";
    string s = "a good   example";
    std::cout << so.reverseWords(s) << std::endl;
}