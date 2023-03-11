/**
 * @file JZ40 最小的k个数
 * @brief 输入整数数组 arr ，找出其中最小的 k 个数。
    例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

    思路：最大堆
        - priority_queue<int> bigQ;
        - C++ 中 priority_queue 默认大根堆
 */


#include <queue>
#include <vector>
#include <iostream>

using std::vector;



class Solution {
public:
    class Greater {
    public:
        bool operator()(const int x, const int y) {
            return x > y;
        }
    };

    /**
     * @brief 利用大根堆：首先入堆k个，然后逐个比较堆顶元素和剩余数组元素
     * @note C++ 中priority_queue默认大根堆
     * @param arr 
     * @param k 
     * @return vector<int> 
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res{};
        if(k <= 0 || arr.empty())
            return res;

        if (k > arr.size()) {
            return arr;
        }

        std::priority_queue<int> maxQ;
        for(int i = 0; i < k; ++i)
            maxQ.push(arr[i]);
        
        for(int i = k; i < arr.size(); ++i) {
            if (arr[i] < maxQ.top()) {
                maxQ.pop();
                maxQ.push(arr[i]);
            }
        }

        for(int i = 0; i < maxQ.size(); ++i) {
            res.push_back(maxQ.top());
            maxQ.pop();
        }

        return res;
    }


    vector<int> getGreaterNumbers(vector<int>& nums, int k) {
        if (k <= 0 || nums.empty())
            return {};
        
        if (k > nums.size()) {
            return nums;
        }

        std::priority_queue<int, vector<int>, Greater> minQ;
        for(int i = 0; i < k; ++i) minQ.push(nums[i]);

        vector<int> res;
        for(int i = k; i < nums.size(); ++i) {
            if (nums[i] > minQ.top()) {
                minQ.pop();
                minQ.push(nums[i]);
            }
        }

        while(!minQ.empty()) {
            res.push_back(minQ.top());
            minQ.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 2, 1, 56};
    vector<int> ret = s.getGreaterNumbers(nums, 9);
    vector<int> ret1 = s.getLeastNumbers(nums, 9);
   
    for(auto e : ret) std::cout << e << " ";
    std::cout << std::endl;

    for(auto e : ret1) std::cout << e << " ";
    std::cout << std::endl;
}