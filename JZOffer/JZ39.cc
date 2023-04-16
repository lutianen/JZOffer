/**
 * @file JZ39 数组中出现次数超过一半的数字
 * @brief 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
            你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *  思路：
        1. 利用 map 统计数字出现的频次
        2. 摩尔投票法
        3. 排序，中间值必为结果
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    // 摩尔投票法
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;

        int ret = nums[0];
        int sum = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (ret != nums[i])
                sum--;
            else
                sum++;
            if (sum == 0) {
                ret = nums[++i];
                sum++;
            }
        }

        return ret;
    }

    /// 频次统计
    int majorityElement2(vector<int>& nums) {
        if (nums.size() < 1) return -1;
        map<int, int> m;

        for (auto e : nums) {
            m[e]++;
        }

        int half = nums.size() / 2;
        for (auto e : nums) {
            if (m[e] > half) return e;
        }

        return -1;
    }

    /// 排序
    int majorityElement3(vector<int>& nums) {
        if (nums.empty()) return -1;
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

int main() {
    Solution s;
    vector<int> nums;

    int k;
    while (cin >> k) {
        nums.push_back(k);
        if (getchar() == '\n') break;
    }

    int ret = s.majorityElement(nums);
    cout << ret << endl;
}