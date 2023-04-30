/**
 * @file LQ611 有效三角形的个数
 * @brief
 *      给定一个包含非负整数的数组nums，返回其中可以组成三角形三条边的三元组个数。
 * 思路：
    判断三条边能组成三角形的条件为：
        任意两边之和大于第三边，任意两边之差小于第三边。
        三条边长从小到大为 a、b、c，当且仅当 a + b > c 这三条边能组成三角形。
    问题转化为：两数之和大于第三个数构成的二元组的个数
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int triangleNumber2(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = n - 1; i >= 2; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] <= nums[i])
                    l++;
                else {
                    cnt += r - l;
                    --r;
                }
            }
        }

        return cnt;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        vector<int> path{};
        int ret = 0;
        DFS(nums, 0, path, ret);

        return ret;
    }

private:
    void DFS(vector<int>& nums, int k, vector<int>& path, int& cnt) {
        if (k < 0 || k > nums.size() || path.size() > 3) return;

        if (path.size() == 3 && isValidTriangle(path)) cnt++;

        for (int i = k; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            DFS(nums, i + 1, path, cnt);
            path.pop_back();
        }
    }

    bool isValidTriangle(vector<int>& vec) {
        return vec[0] + vec[1] > vec[2] && vec[1] + vec[2] > vec[0] &&
               vec[0] + vec[2] > vec[1];
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums{4, 2, 3, 4};
    Solution so;
    cout << so.triangleNumber(nums) << endl;
    cout << so.triangleNumber2(nums) << endl;
}