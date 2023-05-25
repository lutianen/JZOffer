/**
 * @brief 全排列
 * @link https://leetcode.cn/problems/permutations/
 */

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::function;
using std::unordered_set;
using std::vector;

class Solution {
public:
    vector<vector<int>> permute2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {{nums[0]}};
        vector<vector<int>> res{};
        vector<int> path{};
        unordered_set<int> uset;

        function<void(int idx)> dfs = [&](int idx) {
            if (idx >= n) {
                res.push_back(path);
                return;
            }

            for (int i = 0; i < n; ++i) {
                if (uset.find(nums[i]) != uset.end()) continue;

                uset.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(idx + 1);
                uset.erase(nums[i]);
                path.pop_back();
            }
        };
        dfs(0);
        return res;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {{nums[0]}};
        vector<vector<int>> res{};
        vector<int> path{};
        unordered_set<int> uset;

        backTrace(0, nums, n, res, path, uset);
        return res;
    }

private:
    void backTrace(int idx, const vector<int>& nums, int n, vector<vector<int>>& res, vector<int>& path,
                   unordered_set<int>& uset) {
        if (idx >= n) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (uset.find(nums[i]) != uset.end()) continue;

            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backTrace(idx + 1, nums, n, res, path, uset);
            path.pop_back();
            uset.erase(nums[i]);
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution so;
    auto ret = so.permute(nums);
    for (const auto& vec : ret) {
        for (const int e : vec) {
            cout << e << ", ";
        }
        cout << endl;
    }
}
