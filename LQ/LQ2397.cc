/**
 * @file LQ2397 被列覆盖的最多行数
 * @brief
        给你一个下标从0开始的mxn二进制矩阵mat和一个整数cols，表示你需要选出的列数
        如果一行中，所有的 1 都被你选中的列所覆盖，那么我们称这一行 被覆盖 了。
        请你返回在选择 cols 列的情况下，被覆盖 的行数 最大 为多少。

    链接：https://leetcode.cn/problems/maximum-rows-covered-by-columns
 */

#include <algorithm>
#include <functional>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix[0].size(), ans = 0;
        vector<int> col;
        function<void(int)> dfs = [&](int idx) {
            if (idx >= n) {
                if (col.size() == static_cast<size_t>(numSelect))
                    ans = max(cntCover(matrix, col), ans);
                return;
            }

            // 不选第 idx 列
            dfs(idx + 1);

            // 选择第 idx 列
            col.push_back(idx);
            dfs(idx + 1);
            col.pop_back();
        };

        dfs(0);
        return ans;
    }

private:
    int cntCover(vector<vector<int>>& matrix, vector<int>& column) {
        unordered_set<int> uset;
        // 用于快速判断非选中列
        for (const auto& e : column) uset.insert(e);
        int cnt = 0;
        // 计算覆盖数
        for (const auto& row : matrix) {
            int sum = 0;
            for (size_t i = 0; i < row.size(); ++i)
                if (uset.find(i) == uset.end()) sum += row[i];
            cnt += sum == 0 ? 1 : 0;
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> matrix{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 0, 1}};
    Solution so;
    so.maximumRows(matrix, 2);
}