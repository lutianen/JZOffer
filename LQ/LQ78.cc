/**
 * @file LQ78 子集
 * @brief 给你一个整数数组 nums，数组中的元素互不相同
        返回该数组所有可能的子集（幂集）。解集不能包含重复的子集
        你可以按任意顺序返回解集。
 *  思路：回溯算法
        - 组合问题、分割问题都是收集树的叶子节点；而子集问题是收集树的所有节点；
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path{};
        vector<vector<int>> ps{};
        backtrack(nums, 0, path, ps);
        return ps;
    }

private:
    void backtrack(const vector<int>& nums, int index, vector<int>& path,
                   vector<vector<int>>& ps) {
        // 收集节点数据
        ps.push_back(path);
        // 遍历到最后一个则结束递归
        if (static_cast<size_t>(index) >= nums.size()) return;
        // 下一个数字
        for (size_t i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, ps);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};
    Solution so;
    vector<vector<int>> ret = so.subsets(nums);
    std::cout << "[" << std::endl;
    for (const auto& vec : ret) {
        for (const int e : vec) std::cout << e << " ";
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}