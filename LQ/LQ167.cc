/**
 * @file LQ167 两数之和 II - 输入有序数组
 * @brief https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 0) return {};

        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target)
                l++;
            else if (sum > target)
                r--;
            else
                break;
        }

        return {l + 1, r + 1};
    }
};

int main() {
    vector<int> nums{-1, 0};
    Solution s;
    vector<int> rest = s.twoSum(nums, -1);

    for (int e : rest) {
        cout  << e << " ";
    }
    cout << endl;
}