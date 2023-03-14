/**
 * @file LQ26. 删除有序数组中的重复项
 * @brief 给你一个升序排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，
        返回删除后数组的新长度。元素的 相对顺序 应该保持 一致

    思路：快慢指针
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if(nums.size() < 2) return nums.size();

        int slow = 0;
        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    while(n--) {
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