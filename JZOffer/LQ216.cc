/**
 * @file LQ216 组合总和 III
 * @brief 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
        只使用数字1到9
        每个数字 最多使用一次 
        返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

    链接：https://leetcode.cn/problems/combination-sum-iii
 */


#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    int sum;
    
    void backtracking(int n, int k, int s) {
        if (path.size() == k) {
            if (sum == n) res.push_back(path);
            return;
        }

        for (int i = s; i <= 9; ++i) {
            path.push_back(i);
            sum += i;

            // 剪枝
            if (sum > n) {
                sum -= i;
                path.pop_back();
                return;
            }
            backtracking(n, k, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
};