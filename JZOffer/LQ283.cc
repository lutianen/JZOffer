/**
 * @file LQ283 移动零
 * @brief 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
        请注意 ，必须在不复制数组的情况下原地对数组进行操作。
 * 思路：双指针
 */

#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2)
            return;

        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[j++] = nums[i];
            }
        }

        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {0,1};
    s.moveZeroes(nums);
    return 0;
}