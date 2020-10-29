/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.63%)
 * Total Accepted:    116.5K
 * Total Submissions: 266.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        int height = board.size(), width = board[0].size();
        function<bool(int, int, int)> dfs = [&] (int row, int col, int idx) {
            if (row < 0 || row >= height || col < 0 || col >= width || board[row][col] == '.' || idx >= word.size() || board[row][col] != word[idx]) {
                return false;
            }
            if (idx == word.size() - 1 && board[row][col] == word[idx]) {
                return true;
            }
            char t = board[row][col];
            board[row][col] = '.';
            if (dfs(row + 1, col, idx + 1)) return true;
            if (dfs(row - 1, col, idx + 1)) return true;
            if (dfs(row, col + 1, idx + 1)) return true;
            if (dfs(row, col - 1, idx + 1)) return true;
            board[row][col] = t;
            return false;
        };
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
