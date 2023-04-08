/**
 * @file LQ581 最短无序连续子数组
 * @brief 给你一个整数数组 nums ，你需要找出一个 连续子数组
 *  如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 *  请你找出符合题意的 最短 子数组，并输出它的长度。
 * 思路：将原始数组分为 nums_A, nums_B, nums_C，其中 nums_B 即为最短无序连续子数组（寻找边界）
    1. 首先将原数组复制一份并排序，找到两侧第一个不相同的数组下标，
        两者之间就是最长无序子数组的长度；
        时间复杂度：O(NlogN)
        空间复杂度：O（N）
    2.寻找有序数组 nums_A, nums_C 的边界
 */

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        if (is_sorted(nums.begin(), nums.end())) return 0;

        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int left = 0;
        for (; left < nums.size(); left++) {
            if (numsSorted[left] != nums[left]) break;
        }

        int right = nums.size() - 1;
        for (; right >= 0; right--) {
            if (numsSorted[right] != nums[right]) break;
        }

        return right - left + 1;
    }

    int findUnsortedSubarray2(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();

        // right - 表示 nums_C 所取得的最大范围
        // left - 表示 nums_A 所取得的最大范围
        // nums_B = nums[left, right]
        int maxN = INT_MIN, right = -1;
        int minN = INT_MAX, left = -1;

        for (int i = 0; i < n; i++) {
            if (maxN > nums[i])
                right = i;
            else
                maxN = nums[i];

            if (minN < nums[n - i - 1])
                left = n - i - 1;
            else
                minN = nums[n - i - 1];
        }

        return right == -1 ? 0 : right - left + 1;
    }
};
