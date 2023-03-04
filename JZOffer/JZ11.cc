/**
 * @file JZ11 旋转数组的最小数字
 * @brief 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。
    注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
 * 
 */

#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:

    /**
     * @brief 根据旋转数组特性，旋转轴一定比前者大，如果存在旋转轴，则一定出现断崖，找到最小值；否则，返回第一个数字（一定最小）
     * 
     * @param numbers 
     * @return int 
     */
    int minArray(vector<int>& numbers) {
        int length = numbers.size();
        int cur = 0;

        for (int i = 0; i < length - 1; ++i) {
            if (numbers[cur] <= numbers[cur + 1])
                cur++;
            else return numbers[cur+1];   
        }

        return numbers[0];        
    }
};

int main() {
    Solution s;
    vector<int> numbers{1, 3, 5};
    int ret = s.minArray(numbers);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}