/**
 * @file LQ77 组合
 * @brief 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合
    你可以按 任何顺序 返回答案。

    思路：回溯算法
        组合问题是回溯法解决的经典问题
 */


#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k < 0) 
            return {};

        backtracking(n, k, 1);
        return res;
    }

    void backtracking(int n, int k, int startIndex) {
        if(path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n; ++i) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};



