/**
 * @brief 找两个正序数组的中位数
 * @link https://leetcode.cn/problems/median-of-two-sorted-arrays/
 */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp = merge(nums1, nums2);
        int n = nums1.size() + nums2.size();
        return (n & 1) == 1 ? temp[n / 2] : (temp[n / 2 - 1] + temp[n / 2]) * 0.5;
    }

private:
    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> temp;
        auto it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 > *it2) {
                temp.push_back(*it2);
                ++it2;
            } else {
                temp.push_back(*it1);
                ++it1;
            }
        }

        while (it1 != nums1.end()) {
            temp.push_back(*it1);
            ++it1;
        }
        while (it2 != nums2.end()) {
            temp.push_back(*it2);
            ++it2;
        }

        return temp;
    }
};

int main() {
    vector<int> nums1{1, 4}, nums2{2, 5};
    Solution so;
    std::cout << so.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}