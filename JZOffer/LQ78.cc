/**
 * @file LQ78 子集
 * @brief 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
        解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *  思路：回溯算法 - 组合问题、分割问题都是收集树的叶子节点；而子集问题是收集树的所有节点；
 */


#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();

        backTracking(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res {};
    vector<int> path {};

    void backTracking(vector<int>& nums, int index) {
        // 收集节点
        res.push_back(path);
        
        // 终止条件
        if (index >= nums.size())
            return;

        for (int i = index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};