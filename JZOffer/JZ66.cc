/**
 * @file JZ66 构建乘积数组
 * @brief 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
    其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
    不能使用除法。

 * 思路：前缀乘积数组
    利用两个前缀乘积数组，left[i]、right[i] 分别表示 a[0, i) 或 a(i, size() - 1] 的乘积
 */

#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty())
            return a;

        // 标识 [0, i) 或 (i, size() - 1] 的乘积
        vector<int> left (a.size(), 1);
        vector<int> right (a.size(), 1);

        // 左侧前缀乘积数组
        for (int i = 1; i < a.size(); ++i) {
            left[i] = a[i - 1] * left[i - 1];
        }
        // 右侧前缀乘积数组
        for (int i = a.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i + 1];
        }

        // 结果：res[i] = left[i] * right[i]
        vector<int> res(a.size());
        for (int i = 0; i < a.size(); ++i) {
            res[i] = left[i] * right[i];
        }
        
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a {1, 2, 3, 4, 5};
    vector<int> ret = s.constructArr(a);
    for(auto e : ret) {
        std::cout << e << ", ";
    }
}