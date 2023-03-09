/**
 * @file JZ17 打印从1到最大的n位数
 * @brief 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
    比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
    说明：
        用返回一个整数列表来代替打印
        n 为正整数

    思路：回溯算法
 */

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> printNumbers(int n) {
        if (n <= 0) return {};

        vector<string> temp;
        string cur;
        for(int i = 1; i <= n; ++i ){
            DFS(temp, cur, 0, i);
        }

        vector<int> r;
        for(auto e : temp) {
            r.push_back(std::stoi(e));
        }

        return r;
    }

private:
    /**
     * @brief 回溯算法
     * 
     * @param res 结果
     * @param cur 当前值
     * @param x 当前值的第 x 位
     * @param len 当前值的总位数
     */
    void DFS(vector<string>& res, string& cur, int x, int len) {
        if (x == len) {
            res.push_back(cur);
            return;
        }

        // 首位起始值：第 0 位则从 1 开始，避免出现 0 开头的数字字符串
        int start = (x == 0) ? 1 : 0;

        // 回溯
        for(int i = start; i < 10; ++i) {
            cur.push_back(NUMBERS[i]);
            DFS(res, cur, x + 1, len);
            cur.pop_back();
        }
    }

    const char NUMBERS[10] = {'0', '1', '2', '3', '4',
                     '5', '6', '7', '8', '9'};
};

int main() {
    Solution s;
    vector<int> ret = s.printNumbers(3);
    // for (auto iter = ret.begin(); iter != ret.end(); ++iter){
    //     std::cout << *iter << " ";

    for(auto& v : ret)
        std::cout << v << " ";
    std::cout << "\n------------" << std::endl;
}