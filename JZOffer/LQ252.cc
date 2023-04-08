/**
 * @file LQ252 会议室
 * @brief 给定一个会议时间安排的数组，
        每个会议时间都会包括开始和结束的时间[[s1,e1],[s2,e2],...](si < ei)，请你判断一个人是否能够参加这里面的全部会议。
 *
 *  思路：贪心
        按照区间左侧排序，然后依次检查相邻的前一个的结束和后一个的开始是否重叠
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 贪心
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(),
        //  [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        sort(intervals.begin(), intervals.end(), [&](auto a, auto b) { return a[0] < b[0]; });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i - 1][1] > intervals[i][0]) return false;
        }

        return true;
    }
};


int main() {
    vector<vector<int>> nums {
        {0, 3},
        {5, 10},
        {15, 20},
    };

    Solution s;
    cout << s.canAttendMeetings(nums) << '\n';
}
