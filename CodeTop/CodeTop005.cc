/**
 * @brief 三数之和
 * @link https://leetcode.cn/problems/3sum/
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::sort;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> valIdx;
        for (int i = 0; i < n; ++i)
            valIdx[nums[i]] = i;

        vector<int> res {};
        for (int i = 0; i < n; ++i) {
            int left = target - nums[i];
            auto iter = valIdx.find(left);
            if (iter != valIdx.end() && valIdx[left] != i) {
                res.push_back(i);
                res.push_back(valIdx[left]);
                break;
            }
        }

        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res {};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> temp{nums[i], nums[left], nums[right]};
                    res.emplace_back(temp);
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++; right--;
                } else if (sum < 0)
                    ++left;
                else 
                    --right;
            }
        }

        return res;
    }

    // 优化版本：直接使用迭代器
    vector<vector<int>> threeSum2(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(auto i = nums.begin(); i != std::prev(nums.end(), 2); ++i) {
            if (*i > 0) break;
            if (i > nums.begin() && *i == *(i - 1)) continue;

            auto j = std::next(i);
            auto k = std::prev(nums.end());
            while(j < k) {
                const int sum = *i + *j + *k;
                if (sum < 0) 
                    ++j;
                else if (sum > 0)
                    --k;
                else {
                    res.push_back({*i, *j, *k});
                    while (j < k && *j == *(j + 1)) j++;
                    while (j < k && *k == *(k - 1)) k--; 
                    ++j; --k;    
                } 
            }
        }

        return res;
    }
};

int main(){
    Solution so;
    vector<int> nums{-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    vector<vector<int>> ret = so.threeSum(nums);
    for (const auto& vec : ret ) { 
        for (const int num : vec) 
            cout << num << " ";
        cout << endl;
    }

    cout << "---" << endl;

    vector<int> nums2{1, 2, 3, -2, -5, -3};
    auto ret2 = so.twoSum(nums2, -3);
    for (const int num : ret2) 
        cout << num << " ";
    cout << endl;
    cout << "---" << endl;

    vector<int> nums3{-1, 0, 1, 2, -1, -4};
    auto ret3 = so.threeSum2(nums3);
    for (const auto& vec : ret3) { 
        for (const int num : vec) 
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
