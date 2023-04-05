/**
 * @file LQ347 前 K 个高频元素
 * @brief 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k
 *      高的元素。你可以按 任意顺序 返回答案。
 * 思路：哈希表（频率统计） + 大根堆（自定义仿函数）
 */

#include <functional>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k < 0 || nums.empty()) return {};

        map<int, int> numFreq;
        for (auto num : nums) numFreq[num]++;

        // priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>que;
        auto Cmp = [](pair<int, int>& a, pair<int, int>& b) -> bool {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(Cmp)>
            que(Cmp);

        for (auto& p : numFreq) que.push(p);
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(que.top().first);
            que.pop();
        }

        return ret;
    }
};