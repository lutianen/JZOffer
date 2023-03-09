/**
 * @file JZ21 调整数组顺序使奇数位于偶数前面
 * @brief 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
    使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
 * 思路：双指针 - 对撞指针
 *      左指针寻找奇数，右指针寻找偶数，然后交换
 */


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> odd{};
        vector<int> even{};

        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] & 1) {
                odd.push_back(nums[i]);
            } else even.push_back(nums[i]);
        }

        vector<int> res {};
        for(int i = 0; i < odd.size(); ++i) {
            res.push_back(odd[i]);
        }
        
        for(int i = 0; i < even.size(); ++i) {
            res.push_back(even[i]);
        }

        return res;
    }


    // 双指针 - 对撞指针
    // 左指针寻找奇数，右指针寻找偶数，然后交换
    vector<int> exchange2(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            // 寻找左侧第一个偶数
            while(left < right && (nums[left] & 1) == 1) {
                left++;
            }

            // 寻找右侧第一个奇数
            while(left < right && (nums[right] & 1) == 0) {
                right--;
            }

            // 原地交换
            if (left < right)
                std::swap(nums[left++], nums[right--]);
        }

        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    // vector<int> ret = s.exchange(nums);
    // for (auto& elemet : ret)
    //     std::cout << elemet << std::endl;

    vector<int> ret = s.exchange2(nums);
    for(auto& element: ret)
        std::cout << element << std::endl;
}