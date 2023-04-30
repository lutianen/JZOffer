/**
 * @file LQ18. 四数之和
 * @brief
 * 思路：排序 + 双指针
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> res{};
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1, r = n - 1;
                while (l < r) {
                    if ((long long)nums[i] + nums[j] - target ==
                        -(nums[l] + nums[r])) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    } else if ((long long)nums[i] + nums[j] - target >
                               -(nums[l] + nums[r]))
                        r--;
                    else
                        l++;
                }
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
    int target = -294967296;

    Solution so;
    auto ret = so.fourSum(nums, target);
    for (const auto& vec : ret) {
        for (const int e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }
}