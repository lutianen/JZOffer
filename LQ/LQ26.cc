/**
 * @file LQ26 删除有序数组中的重复项
 * @brief
 给你一个升序排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，
        返回删除后数组的新长度。元素的 相对顺序 应该保持 一致

    思路：快慢指针 - nums[++l] = nums[r]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief 快慢指针
     *     nums[++l] = nums[r]
     * @param nums
     * @return int
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int l = 0;
        for (int r = 0; r < nums.size(); ++r)
            if (nums[l] != nums[r]) nums[++l] = nums[r];

        return l + 1;
    }
};

int main() {
    // 6
    // 1 2 3 3 4 4
    int n;
    cin >> n;
    vector<int> nums;
    while (n--) {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    Solution so;
    int k = so.removeDuplicates(nums);

    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}