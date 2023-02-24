/**
 * @file LQ01 两数之和
 * @brief 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案
    
    链接：https://leetcode.cn/problems/two-sum

    思路：利用 map<nums[i], i> 记录元素值和对应的下标
        遍历数组，并再 map 中查找对应的元素是否存在
 */

#include <vector>
#include <map>

using std::vector;
using std::map;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> temp;

        // 将元素值和对应下标先存入map中
        for(int i = 0; i < nums.size(); ++i) {
            temp[nums[i]] = i;
        }

        vector<int> res;

        // 遍历数组查找对应元素
        for(int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            if (temp.find(left) != temp.end()) {
                if (temp[left] == i) continue;

                res.push_back(temp[left]);
                res.push_back(i);
                break;
            }            
        }

        return res;
    }
};