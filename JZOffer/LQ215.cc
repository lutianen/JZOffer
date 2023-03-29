/**
 * @file LQ215 数组中的第K个最大元素
 * @brief 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
    请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
    你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

    链接：https://leetcode.cn/problems/kth-largest-element-in-an-array

    思路：小根堆排序
 * 
 */

#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq;

        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};