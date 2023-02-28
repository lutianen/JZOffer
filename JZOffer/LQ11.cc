/**
 * @file LQ11 最多水的容器
 * @brief 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
        找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
        返回容器可以储存的最大水量。
        说明：你不能倾斜容器。

    链接：https://leetcode.cn/problems/container-with-most-water
 */

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    /**
     * @brief 双指针(对撞指针)
     *   向内移动 短 板，面积可以增大；
     *   向内移动 长 板，面积一定减小。
     *   将两个变量（长度、宽度）减少为一个（长度），因为无论左指针、右指针向内移动，宽度都固定减少 1；
     * @param height 
     * @return int 
     */
    int maxArea(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        
        int cap = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            if (height[left] < height[right]) {
                cap = std::max(cap, height[left] * (right - left));
                left++;
            } else {
                cap = std::max(cap, height[right] * (right - left));
                right--;
            }
        }
        
        return cap;
    }
};