/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.09%)
 * Total Accepted:    79.4K
 * Total Submissions: 108.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：4
 * 输出：[
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 */
class Solution {
public:
    vector<string> tostring(vector<int>& board) {
        vector<string> strboard;
        for (int i = 0; i < board.size(); ++i) {
            string s = "";
            for (int j = 0; j < board.size(); ++j) {
                s.push_back(j == board[i] ? 'Q' : '.');
            }
            strboard.push_back(s);
        }
        return strboard;
    }

    bool canput(vector<int>& board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i] == col) {
                return false;
            }
            if (i + board[i] == row + col || i - board[i] == row - col) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n, -1);
        vector<vector<string>> result;
        function<void(int)> backtrack = [&] (int start) {
            if (start == n) {
                result.push_back(tostring(board));
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (canput(board, start, i)) {
                    board[start] = i;
                    backtrack(start + 1);
                }
            }
        };
        backtrack(0);
        return result;
    }
};
