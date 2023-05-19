/**
 * @brief 
 */

#include <sys/types.h>
#include <iostream>
#include <cstdlib>
#include <type_traits>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        bool sorted = true;
        for (int i = left; i < right; i++) 
            if (nums[i] > nums[i+1]) sorted = false;
        if (sorted) return;

        std::swap(nums[right], nums[(rand() % (right - left + 1)) + left]);
        int i = left, j = right - 1;
        int povit = nums[right];

        while(i < j) {
            while(i <= j && nums[i] < povit) ++i;
            while(i <= j && nums[j] > povit) --j;
            if (i < j)
                std::swap(nums[i++], nums[j--]);
        }

        std::swap(nums[right], nums[i]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }
};

int main() {
    auto t0 = std::chrono::high_resolution_clock::now();
    vector<int> nums {-9, -1, 0, 5, 2, 1, -10, -4, 4, 3, 1, 4};
    
    Solution so;
    so.sortArray(nums);
    auto delta = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - t0);

    for(const int num : nums)
        cout << num << ", ";
    cout << endl;

    cout << "It cost " << delta.count() << " us." << endl;
}