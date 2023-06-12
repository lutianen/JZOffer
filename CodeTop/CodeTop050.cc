/**
 * @brief 子集
 * @link https://leetcode.cn/problems/subsets/
 */

#include <functional>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {};

        vector<vector<int>> res;
        vector<int> path;

        // 回溯算法 - dfs
        std::function<void(int)> dfs = [&](size_t idx) -> void {
            res.push_back(path);
            if (idx >= nums.size()) {
                return;
            }

            for (size_t i = idx; i < nums.size(); ++i) {
                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution so;
    vector<vector<int>> ret = so.subsets(nums);

    for (const auto& vec : ret) {
        for (const int e : vec) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}