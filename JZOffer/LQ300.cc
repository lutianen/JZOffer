/**
 * @file LQ300 最长递增子序列
 * @brief 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *  进阶：将算法的时间复杂度降低到 O(n log(n)) 吗?

    思路：动态规划
        d[i]，表示已 nums[i] 为结尾的 nums[0,...,i] 的 LIS 的长度
        nums[i] > nums[j]:
            d[i] = max(d[i], d[j] + 1)
        时间复杂度：O（N^2)
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        // // d[i] 表示 nums 以 nums[i] 为结尾的最长递增子序列的长度
        // vector<int> d(nums.size(), 1);
        // int ret = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < nums[i]) {
        //             d[i] = max(d[i], d[j] + 1);
        //         }
        //     }

        //     ret = max(ret, d[i]);
        // }

        // return ret;

        vector<int> d(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    d[i] = max(d[i], d[j] + 1);
            }
        }

        return *max_element(d.begin(), d.end());
    }
};

/**
 * @brief 先使用 回溯 求出所用递增子序列，然后求最值，超时
 */
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<vector<int>> temp = findSubsequences(nums);
        int ret = 0;
        for (auto& vec : temp) {
            ret = max(ret, static_cast<int>(vec.size()));
        }

        return ret;
    }

private:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path{};
        vector<vector<int>> ret;

        backTrace(nums, 0, path, ret);
        return ret;
    }

    void backTrace(const vector<int>& nums, int startIdx, vector<int>& path,
                   vector<vector<int>>& ret) {
        if (path.size() >= 1) {
            ret.push_back(path);
        }

        // 使用set对本层元素进行去重
        unordered_set<int> uset;
        for (int i = startIdx; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() ||
                uset.find(nums[i]) != uset.end())
                continue;

            // 记录这个元素在本层用过了，本层后面不能再用了
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backTrace(nums, i + 1, path, ret);
            path.pop_back();
        }
    }
};

int main() {
    Solution so;
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << so.lengthOfLIS(nums);
}