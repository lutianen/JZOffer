/**
 * @brief x 的平方根
 * @link https://leetcode.cn/problems/sqrtx/
 */

#include <iostream>

class Solution {
public:
    // 暴力查找
    // 时间复杂度 O(x*0.5)
    int mySqrt(int x) {
        if (x == 1) return 1;

        size_t X = x;
        int res = 0;
        for (size_t i = 0; i * i <= X; ++i) {
            res = i;
        }

        return res;
    }

    // 二分法
    // 时间复杂度 O(log n)
    int mySqrt2(int x) {
        size_t left = 0, right = x;
        int res = left;
        while(left <= right) {
            size_t mid = left + ((right - left) >> 1);
            if (mid * mid < x) {
                left = mid + 1;
                res = mid;
            } else if (mid * mid > x) {
                right = mid - 1;
            } else {
                res = mid;
                break;
            }
        }

        return res;
    }
};

int main() {
    Solution so;
    int x = 2;
    std::cout << so.mySqrt(x) << std::endl;
}