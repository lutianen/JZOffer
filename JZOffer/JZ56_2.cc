/**
 * @file JZ56_2 数组中数字出现的次数 II
 * @brief 在一个数组nums中除一个数字只出现一次之外，其他数字都出现了三次。
        请找出那个只出现一次的数字。
 *  思路：
        1. map 词频统计
        2. 位运算
        3. 数学：
            ret = (3 * sum(a, b, c) - (a+a+a+b+b+b+c)) / 2
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        if (nums.empty()) return -1;

        std::unordered_map<int, int> umap;
        for (int e : nums) umap[e]++;

        int ret = -1;
        for (int e : nums) {
            if (umap[e] == 1) {
                ret = e;
                break;
            }
        }
        return ret;
    }
    int singleNumber_3(std::vector<int>& nums) {
        std::unordered_set<int> uset;

        // signed integer overflow
        long long sum0 = 0;
        for (const auto& num : nums) {
            uset.insert(num);
            sum0 += num;
        }
        long long sum = 0;
        for (auto iter : uset) sum += iter;
        return (3 * sum - sum0) / 2;
    }
};

int main(int argc, char* argv[]) {
    Solution so;
    std::vector<int> nums{3, 4, 3, 3, 9, 8, 9, 8, 9, 8};
    std::cout << so.singleNumber(nums) << std::endl;
}