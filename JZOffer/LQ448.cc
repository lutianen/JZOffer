/**
 * @file LQ448 找到所有数组中消失的数字
 * @brief 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

    思路：set
 */


#include <unordered_set>
#include <vector>
#include <iostream>

using std::vector;
using std::unordered_set;
using std::cout;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        unordered_set<int> uset;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            uset.insert(i);
        }

        vector<int> res{};
        for (int i = 0; i < n; i++) {
            if (uset.find(nums[i]) != uset.end()) {
                uset.erase(nums[i]);
            }
        }

        for (auto i : uset)
            res.push_back(i);

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ret = s.findDisappearedNumbers(nums);
    for(auto i : ret)
        cout << i << " ";
    return 0;
}