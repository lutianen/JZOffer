/**
 * @file JZ49 丑数
 * @brief 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
        求按从小到大的顺序的第 n 个丑数

    思路：
        1. set + 小根堆
        2. 动态规划
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using std::priority_queue;
using std::unordered_set;
using std::vector;

class Solution {
public:
    // set + 小根堆
    int nthUglyNumber(int n) {
        if (n <= 0) return -1;

        unordered_set<long long> uset;
        priority_queue<long long, vector<long long>, std::greater<long long>>
            qQue;

        uset.insert(1);
        qQue.push(1);

        for (int i = 1; i < n; i++) {
            long long uglyCurr = qQue.top();
            qQue.pop();

            // 必须使用 for 循环，不能取最小值
            for (int f : FACTORS) {
                long long uglyNext = f * uglyCurr;
                if (uset.count(uglyNext) == 0) {
                    uset.insert(uglyNext);
                    qQue.push(uglyNext);
                }
            }
        }

        return qQue.top();
    }

    /**
     * @brief 动态规划解答
     */
    int nthUglyNumber2(int n) {
        if (n < 0) return -1;

        vector<int> uns(n);
        uns[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; i++) {
            uns[i] = std::min(std::min(uns[p2] * 2, uns[p3] * 3), uns[p5] * 5);

            if (uns[i] == uns[p2] * 2) p2++;
            if (uns[i] == uns[p3] * 3) p3++;
            if (uns[i] == uns[p5] * 5) p5++;
        }

        return uns[n - 1];
    }

private:
    const int FACTORS[3] = {2, 3, 5};
};

int main() {
    Solution s;
    std::cout << s.nthUglyNumber(1000) << std::endl;
    std::cout << s.nthUglyNumber2(1000) << std::endl;
}