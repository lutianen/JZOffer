/**
 * @file LQ47 全排列 II
 * @brief  给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *  思路：回溯 + 去重
        - 去重一定要对元素进行排序，这样方便通过相邻节点来判断是否重复使用了
        - 一般来说：组合问题和排列问题是在树形结构的叶子节点上收集结果，而子集问题就是取树上所有节点的结果
 */


#include <vector>
#include <algorithm>

using std::sort;
using std::vector;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();

        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        
        backTracking(nums, used);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过 
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1]) continue;

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backTracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};