/**
 * @file JZ61 扑克牌中的顺子
 * @brief
        从若干副扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
        2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为0,可以看成任意数字。A不能视为14

    思路：假设最小值为 x，则正常情况下最大值为 x + 4，它们的差值 D = 4 < 5；
         另外，正常情况下，不能出现重复数字
 */

#include <limits.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using std::set;
using std::vector;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int zeroNum = 0, maxV = INT_MIN, minV = INT_MAX;
        set<int> st;
        for (int& e : nums) {
            if (e != 0) {
                // maxV = std::max(maxV, e);
                // minV = std::min(minV, e);

                maxV = maxV > e ? maxV : e;
                minV = minV < e ? minV : e;
                st.insert(e);
            } else
                zeroNum++;
        }

        // if (maxV - minV >= 5 || (st.size() + zeroNum != 5)) return false;
        // return true;

        return (static_cast<size_t>(maxV - minV) < nums.size()) &&
               (st.size() + zeroNum == nums.size());
    }

    // 相比于方法 1，利用了 set
    // 的自身有序性（底层容器为红黑树），则不用刻意利用变量记录最值
    bool isStraight2(vector<int>& nums) {
        // 利用 set
        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                if (s.find(nums[i]) == s.end())
                    s.insert(nums[i]);
                else
                    return false;
            }
        }
        return *s.rbegin() - *s.begin() < 5;
    }
};

int main(int argc, char* argv[]) {
    int k;
    std::cin >> k;
    vector<int> nums(k);

    for (int i = 0; i < k; i++) {
        std::cin >> nums[i];
    }

    Solution so;
    std::cout << so.isStraight(nums) << std::endl;
}