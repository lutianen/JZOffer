/**
 * @file LQ56. 合并区间
 * @brief 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
        请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

    链接：https://leetcode.cn/problems/merge-intervals
 * 
    思路：贪心算法
        - 自定义排序
 */


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;

        // 按照左端点排序
        sort(intervals.begin(), intervals.end(), 
                [](vector<int> a, vector<int> b) { return a[0] < b[0]; } );
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i) {
            // 本区间的左侧小于上一个区间的右侧，则可以合并
            if (intervals[i][0] <= res.back()[1]) {
                // 合并后区间右侧为两区间的最大的
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
    
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;

        // 按照右端点从大到小排序
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) { return a[1] > b[1]; } );
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][1] >= res.back()[0]) {
                // 合并后区间左侧取得二者最小值
                res.back()[0] = min(res.back()[0], intervals[i][0]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> intervals;
    while(n-- > 0) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }

    Solution so;
    vector<vector<int>> res = so.merge2(intervals);

    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
        cout << '[' << res[i][0] << ", " << res[i][1] << "]";
        if (i != res.size() - 1) 
            cout << ", ";
    }
    cout << "]" << endl;
}