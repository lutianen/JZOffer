/**
 * @file CodeTop004.cc
 *
 * @brief 数组中的第 K 个最大元素
 *  给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素
 * @link https://leetcode.cn/problems/kth-largest-element-in-an-array
 *
 * @author https://github.com/lutianen
 * @copyright Copyright (c) 2023
 *  FOR STUDY AND RESEARCH SUPPORT ONLY
 */

#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, std::greater<int>> pque;
        // for (int i = 0; i < k; ++i)
        //     pque.push(nums[i]);

        priority_queue<int, vector<int>, std::greater<int>> pque(
            nums.begin(), nums.begin() + k);

        for (size_t i = k; i < nums.size(); ++i) {
            if (nums[i] > pque.top()) {
                pque.pop();
                pque.push(nums[i]);
            }
        }

        return pque.top();
    }
};

int main() {
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 4;
    Solution so;
    cout << so.findKthLargest(nums, k) << endl;
}
