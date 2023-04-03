/**
 * @file LQ1049 最后一块石头的重量 II
 * @brief 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i
        块石头的重量。

        每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x
        和 y，且 x <= y。那么粉碎的可能结果如下：

            如果 x == y，那么两块石头都会被完全粉碎；
            如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
        最后，最多只会剩下一块 石头。返回此石头 最小的可能重量
        。如果没有石头剩下，就返回 0。

    链接：https://leetcode.cn/problems/last-stone-weight-ii
 *  思路：0 - 1 背包，动态规划
        d[i]，表示容量为 i 时所容纳的石头的重量
        最后一块石头重量为：sum - d[sum/2] - d[sum/2]
 */

#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto e : stones) sum += e;

        int target = sum / 2;
        vector<int> d(sum, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                d[j] = max(d[j], d[j - stones[i]] + stones[i]);
            }
        }

        return sum - d[target] - d[target];
    }
};