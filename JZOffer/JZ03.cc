/**
 * @brief 剑指 Offer 03. 数组中重复的数字
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1
 * 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 */


#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:

    /**
     * @brief 利用集合 set 的不可重复性
     * 首先在 set 中寻找该数字是否已经存在，如不存在，则插入；否则，找到的数字一定是重复的数字
     */
    int findRepeatNumber(vector<int> &nums) {
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
};

int main() {
  vector<int> nums{1, 2, 3, 4, 5, 9, 3, 21, 0};
  Solution mySo;
  int ret = mySo.findRepeatNumber(nums);
  std::cout << ret << std::endl;
}