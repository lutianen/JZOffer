/**
 * @file LQ34 在排序数组中查找元素的第一个和最后一个位置
 * @brief 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
    如果数组中不存在目标值 target，返回 [-1, -1]。
    你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

    链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
 
    思路：二分查找
 */


#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else {
                int i = mid, j = mid;
                while (i < nums.size() && nums[i] == target) i--;
                while (j < nums.size() && nums[j] == target) j++;

                res.push_back(i + 1);
                res.push_back(j - 1);
                break;    
            }
        }

        if (res.empty()) {
            res.push_back(-1);
            res.push_back(-1);
        }

        return res;
    }
};

int main() {
    Solution so;
    int target;
    cin >> target;

    vector<int> nums;
    int a;
    while (cin >> a) {
        nums.push_back(a);
    }

    vector<int> ret = so.searchRange(nums, target);

    cout << '[' << ret[0] << ", " << ret[1] << "]" << endl;
}