/**
 * @file LQ128 最长连续序列
 * @brief 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
        请你设计并实现时间复杂度为 O(n) 的算法解决此问题

    思路：哈希表去重 + 只检测序列中第一个数字开始
 */

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> uset;
        for (auto e : nums)
            uset.insert(e);

        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 0;
            int R = nums[i];

            // 每次只匹配序列最开始的那个数，实现去重
            // 如果存在 前驱值，说明不是序列第一个，跳过
            if (!uset.count(nums[i] - 1)) {
                while (uset.find(R) != uset.end()) {
                    temp++;
                    R++;
                }
                ret = max(ret, temp);
            }
        }

        return ret;
    }
};