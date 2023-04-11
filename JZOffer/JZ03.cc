/**
 * @brief 剑指 Offer 03. 数组中重复的数字
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1
 * 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::endl;
using std::set;
using std::swap;
using std::vector;

class Solution {
public:
    /**
     * @brief 利用集合 set 的不可重复性
     * 首先在 set 中寻找该数字是否已经存在，如不存在，则插入；否则，找到的数字一定是重复的数字
     * 空间复杂度 O(n)，时间复杂度 O(n)
     */
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }

        set<int> s{};
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                return nums[i];
            } else {
                s.insert(nums[i]);
            }
        }

        return -1;
    }

    /**
     * @brief 利用数组下标和数值的关系 - nums[i] == i， 不满足则原地交换
     *  时间复杂度 O(n)，空间复杂度 O(1)
     * @param nums
     * @return int
     */
    int findRepeatNumber2(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        for (int i = 0; i < nums.size();) {
            if (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            } else
                i++;
        }

        return -1;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 3, 7, 0};
    // vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    Solution mySo;
    cout << mySo.findRepeatNumber(nums) << endl;
    cout << mySo.findRepeatNumber2(nums) << endl;
}