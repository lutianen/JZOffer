/**
 * @file LQ503 下一个更大元素 II
 * @brief 给定一个循环数组 nums（ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的
 下一个更大元素 。数字 x
 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
 如果不存在，则输出 -1

   链接：https://leetcode.cn/problems/next-greater-element-ii

   思路：单调栈

 * NOTE 计算机的内存都是线性的，没有真正意义上的环形数组，但是我们可以模拟出环形数组的效果，一般是通过 %  运算符求模（余数），获得环形特效
 */

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @brief 单调栈 + 模拟循环（%）
     * 
     * @param nums 
     * @return vector<int> 
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};

        stack<int> idxStk;
        int n = nums.size();
        vector<int> res(n, -1);
        idxStk.push(0);

        for (int i = 1; i < n * 2; i++) {
            int temp = i % n;
            if (nums[temp] <= nums[idxStk.top()])
                idxStk.push(temp);
            else {
                while (!idxStk.empty() && nums[temp] > nums[idxStk.top()]) {
                    res[idxStk.top()] = nums[temp];
                    idxStk.pop();
                }

                idxStk.push(temp);
            }
        }

        return res;
    }
};