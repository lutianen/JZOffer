/**
 * @file JZ17 打印从1到最大的n位数
 * @brief 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
    比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
    说明：
        用返回一个整数列表来代替打印
        n 为正整数

    思路：回溯 【for循环横向遍历，递归纵向遍历，回溯不断调整结果集】
        - 用递归控制for循环嵌套的数量
        - for 循环选择本层节点
        - 优化回溯算法只有剪枝一种方法
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<int> printNumbers2(int n) {
        if (n <= 0) return {};

        vector<string> res;
        string path;
        for (int len = 1; len <= n; ++len) {
            dfs(0, len, path, res);
        }

        vector<int> nums;
        for (const auto& str : res) {
            nums.push_back(std::stoi(str));
        }
        return nums;
    }

private:
    const char NUMBERS[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    /**
     * @param res 结果
     * @param path 当前值
     * @param x 当前值的第 x 位
     * @param len 当前值的总位数
     */
    void dfs(int x, int len, string& path, vector<string>& res) {
        if (x == len) {
            res.push_back(path);
            return;
        }

        int st = x == 0 ? 1 : 0;
        // for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）)
        for (int i = st; i <= 9; i++) {
            path.push_back(NUMBERS[i]);
            dfs(x + 1, len, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    // vector<int> ret = s.printNumbers(3);
    vector<int> ret = s.printNumbers2(3);
    // for (auto iter = ret.begin(); iter != ret.end(); ++iter){
    //     std::cout << *iter << " ";

    // for (auto& v : ret) std::cout << v << " ";
    // std::cout << std::endl;

    for(const int val : ret) printf("%d ", val);
}