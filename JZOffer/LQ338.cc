/**
 * @file LQ338 比特位计数
 * @brief 给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1
            的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。 
 *  思路：
        1. 逐个统计每个数字中 1 的个数
        2. 动态规划
            d[i]，表示数字 i 中二进制 1 的个数
            (i & 1) == 0:
                d[i] == d[i>>1]
            (i & 1) == 1:
                d[i] == d[i>>1] + 1
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if (n < 0) return {};

        vector<int> cnt;
        for (int i = 0; i <= n; i++) countBit(i, cnt);

        return cnt;
    }

    /**
     * @brief 动态规划
     */
    vector<int> countBits_DP(int n) {
        if (n < 0) return {};

        vector<int> cnt(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            if((i & 1) == 1) 
                cnt[i] = cnt[i >> 1] + 1;
            else 
                cnt[i] = cnt[i >> 1];
        }

        return cnt;
    }

private:
    void countBit(int n, vector<int>& cnt) {
        int temp = n, c = 0;
        for (int i = 0; i < 32; i++) {
            if ((temp & 1) == 1) c++;

            temp >>= 1;
        }

        cnt.push_back(c);
    }
};