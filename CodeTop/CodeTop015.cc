/**
 * @brief 合并两个有序数组
 * @link https://leetcode.cn/problems/merge-sorted-array/
 */

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            swap(nums1, nums2);
            return;
        }

        int idx1 = 0, idx2 = 0;
        vector<int> temp{};
        for (int i = 0; i < m + n; ++i) {
            int val = nums1[idx1] < nums2[idx2] ? nums1[idx1++] : nums2[idx2++];
            temp.push_back(val);

            if (idx1 == m || idx2 == n) break;
        }
        while (idx1 < m) {
            temp.push_back(nums1[idx1++]);
        }
        while (idx2 < n) {
            temp.push_back(nums2[idx2++]);
        }

        swap(temp, nums1);
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            swap(nums1, nums2);
            return;
        }
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        std::sort(nums1.begin(), nums1.end());
    }
};

int main() {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2{2, 5, 6};
    int n = 3;
    Solution so;
    so.merge(nums1, m, nums2, n);

    for (const int e : nums1) cout << e << ", ";
    cout << endl;

    return 0;
}