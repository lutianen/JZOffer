/**
 * @file LQ77 组合
 * @brief 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合
    你可以按 任何顺序 返回答案。

    思路：回溯算法
        组合问题是回溯法解决的经典问题
 */

#include <functional>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine2(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;

        std::function<void(int)> dfs = [&](int idx) {
            if (path.size() >= static_cast<size_t>(k)) {
                ans.push_back(path);
                return;
            }

            for (int i = idx; i <= n; ++i) {
                path.push_back(i);
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
    
    vector<vector<int>> combine(int n, int k) {
        if (k < 0) return {};

        backtracking(n, k, 1);
        return res;
    }

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
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

int main(int argc, char* argv[]) {
    Solution so;
    vector<vector<int>> ret = so.combine2(4, 2);

    for (const auto& vec : ret) {
        for (const int e : vec) std::cout << e << ", ";
        std::cout << std::endl;
    }

    return 0;
}
