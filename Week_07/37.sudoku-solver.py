#
# @lc app=leetcode.cn id=37 lang=python3
#
# [37] 解数独
#
# https://leetcode-cn.com/problems/sudoku-solver/description/
#
# algorithms
# Hard (66.66%)
# Total Accepted:    59.9K
# Total Submissions: 89.8K
# Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
#
# 编写一个程序，通过填充空格来解决数独问题。
# 
# 一个数独的解法需遵循如下规则：
# 
# 
# 数字 1-9 在每一行只能出现一次。
# 数字 1-9 在每一列只能出现一次。
# 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
# 
# 
# 空白格用 '.' 表示。
# 
# 
# 
# 一个数独。
# 
# 
# 
# 答案被标成红色。
# 
# 提示：
# 
# 
# 给定的数独序列只包含数字 1-9 和字符 '.' 。
# 你可以假设给定的数独只有唯一解。
# 给定数独永远是 9x9 形式的。
# 
# 
#
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [set(x for x in range(1, 10)) for _ in range(9)]
        cols = [set(x for x in range(1, 10)) for _ in range(9)]
        boxes = [set(x for x in range(1, 10)) for _ in range(9)]

        blanks = []
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    blanks.append((i, j))
                else:
                    val = int(board[i][j])
                    rows[i].remove(val)
                    cols[j].remove(val)
                    bidx = (i // 3) * 3 + j // 3
                    boxes[bidx].remove(val)

        def dfs(start):
            if start == len(blanks):
                return True
            row, col = blanks[start]
            bidx = (row // 3) * 3 + col // 3
            for val in rows[row] & cols[col] & boxes[bidx]:
                board[row][col] = str(val)
                rows[row].remove(val)
                cols[col].remove(val)
                boxes[bidx].remove(val)
                if dfs(start + 1):
                    return True
                rows[row].add(val)
                cols[col].add(val)
                boxes[bidx].add(val)
                board[row][col] = '.'
            return False
        dfs(0)
