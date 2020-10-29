/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (66.66%)
 * Total Accepted:    59.9K
 * Total Submissions: 89.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * 提示：
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        set<int> origin {1,2,3,4,5,6,7,8,9};
        vector<set<int>> rows(9, set<int>(origin));
        vector<set<int>> cols(9, set<int>(origin));
        vector<set<int>> boxes(9, set<int>(origin));

        vector<pair<int, int>> blanks;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int bidx = (i / 3) * 3 + j / 3;
                if (board[i][j] != '.') {
                    int ch = board[i][j] - '0';
                    rows[i].erase(ch);
                    cols[j].erase(ch);
                    boxes[bidx].erase(ch);
                } else {
                    blanks.push_back(make_pair(i, j));
                }
            }
        }

        function<bool(int)> dfs = [&] (int start) {
            if (start == blanks.size()) {
                return true;
            }
            auto& p = blanks[start];
            int bidx = (p.first / 3) * 3 + p.second / 3;
            set<int> nums(rows[p.first]);
            for (int elem : rows[p.first]) {
                if (cols[p.second].find(elem) == cols[p.second].end() || boxes[bidx].find(elem) == boxes[bidx].end()) {
                    nums.erase(elem);
                }
            }
            for (int val : nums) {
                rows[p.first].erase(val);
                cols[p.second].erase(val);
                boxes[bidx].erase(val);
                board[p.first][p.second] = val + '0';
                if (dfs(start + 1)) {
                    return true;
                }
                rows[p.first].insert(val);
                cols[p.second].insert(val);
                boxes[bidx].insert(val);
            }
            return false;
        };
        dfs(0);
    }
};
