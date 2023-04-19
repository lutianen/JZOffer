/**
 * @file LQ01 两数之和
 * @brief 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出
        和为目标值 target  的那 两个 整数，并返回它们的数组下标。
        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
        你可以按任意顺序返回答案

    链接：https://leetcode.cn/problems/two-sum

    思路：利用 map<nums[i], i> 记录元素值和对应的下标
        遍历数组，并再 map 中查找对应的元素是否存在
 */

#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return {};

        map<int, int> numIdx;
        for (int i = 0; i < nums.size(); ++i) numIdx[nums[i]] = i;

        vector<int> res{};
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            auto iter = numIdx.find(left);
            if (iter != numIdx.end() && iter->second != i) {
                res.push_back(i);
                res.push_back(iter->second);
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') break;
    }
    int target;
    std::cin >> target;

    Solution so;
    vector<int> res = so.twoSum(nums, target);

    for (int e : res) std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}