/**
 * @file LQ496 下一个更大元素 I
 * @brief nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素
 *        给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集
 *        对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
            并且在 nums2 确定 nums2[j] 的下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
          返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素
    思路：单调栈 - 存储下一个更大的元素值
 */

#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) return {};

        // 存放当前元素的下标
        stack<int> indexStk;
        // 存储当前元素以及下一个更大的元素
        unordered_map<int, int> numNext;
        indexStk.push(0);

        // 遍历并维护单调栈
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= nums2[indexStk.top()])
                indexStk.push(i);
            else {
                while (!indexStk.empty() && nums2[i] > nums2[indexStk.top()]) {
                    numNext[nums2[indexStk.top()]] = nums2[i];
                    indexStk.pop();
                }

                indexStk.push(i);
            }
        }

        vector<int> res;
        for (const int e : nums1) {
            if (numNext.find(e) != numNext.end())
                res.push_back(numNext[e]);
            else
                res.push_back(-1);
        }

        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    vector<int> ret = so.nextGreaterElement(nums1, nums2);
}