/**
 * @file JZ61 扑克牌中的顺子
 * @brief 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
    2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14

    思路：假设最小值为 x，则正常情况下最大值为 x + 4，它们的差值 D = 4 < 5；
         另外，正常情况下，不能出现重复数字
 */

#include <vector>
#include <set>
#include <climits>

using std::vector;
using std::set;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int max = INT_MIN, min = INT_MAX;
        
        // 利用 set 
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            
            // 记录最值
            max = max > nums[i] ? max : nums[i];
            min = min < nums[i] ? min : nums[i];

            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            } else return false;
        }

        return max - min < 5;
    }
    
    // 相比于方法 1，利用了 set 的自身有序性（底层容器为红黑树），则不用刻意利用变量记录最值
    bool isStraight2(vector<int>& nums) {
        // 利用 set 
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;

            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            } else return false;
        }

        return *s.rbegin() - *s.begin() < 5;
    }
};