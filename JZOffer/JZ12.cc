/**
 * @file JZ12 矩阵中的路径
 * @brief 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
    链接：https://leetcode.cn/problems/ju-zhen-zhong-de-lu-jing-lcof
 * 思路：利用 DFS，首先将已访问的数据记录下来，然后修改已访问数据，最后改回；注意边界条件的判定和结束条件
 */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (DFS(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool DFS(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[k])
            return false;
        
        // k 达到目标单词的最后一个，并且和当前字符相同，则存在这样的路径
        if (k == word.size() - 1 && board[i][j] == word[k])
            return true;
        
        // 记录当前字符，并暂时修改为其他字符
        char tmp = board[i][j];
        board[i][j] = '*';

        // 上下左右
        bool ret = DFS(board, word, i - 1, j, k + 1) ||
                    DFS(board, word, i + 1, j, k + 1) ||
                    DFS(board, word, i, j - 1, k + 1) ||
                    DFS(board, word, i, j + 1, k + 1);

        // 改回当前字符 - 回溯操作
        board[i][j] = tmp;

        return ret;
    }
};