/**
 * @file LQ79 单词搜索
 * @brief 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
            单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

    链接：https://leetcode.cn/problems/word-search

    思路：DFS + 回溯
 * 
 */

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (DFS(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }

private:
    bool DFS(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[i].size() || idx >= word.size() ||
            board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '*'; 

        if (idx == word.size() - 1)
            return true;

        bool ret =  DFS(board, word, i - 1, j, idx+1) ||
                DFS(board, word, i + 1, j, idx+1) ||
                DFS(board, word, i, j - 1, idx+1)||
                DFS(board, word, i, j + 1, idx+1);

        board[i][j] = temp;
        return ret;
    }
};