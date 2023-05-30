/**
 * @brief 合并区间
 * @link https://leetcode.cn/problems/merge-intervals/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int st = INT_MAX, ed = INT_MIN;
        vector<vector<int>> res{};
        for (size_t i = 0; i < intervals.size(); ++i) {
            st = min(st, intervals[i][0]);
            ed = max(ed, intervals[i][1]);
            if (i == intervals.size() - 1 || ed < intervals[i + 1][0]) {
                res.push_back({st, ed});
                if (i != intervals.size() - 1) st = intervals[i + 1][0];
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> nums{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> nums{{1, 4}, {2, 3}};
    Solution so;
    auto ret = so.merge(nums);

    // Print result
    auto it = ret.begin();
    cout << "[" << (*it)[0] << ", " << (*it)[1];
    for (++it; it != ret.end(); ++it) cout << "], [" << (*it)[0] << ", " << (*it)[1];
    cout << "]" << endl;

    return 0;
}