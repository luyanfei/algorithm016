#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#
# https://leetcode-cn.com/problems/n-queens/description/
#
# algorithms
# Hard (73.09%)
# Total Accepted:    79.4K
# Total Submissions: 108.6K
# Testcase Example:  '4'
#
# n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
# 
# 
# 
# 上图为 8 皇后问题的一种解法。
# 
# 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
# 
# 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
# 
# 
# 
# 示例：
# 
# 输入：4
# 输出：[
# ⁠[".Q..",  // 解法 1
# ⁠ "...Q",
# ⁠ "Q...",
# ⁠ "..Q."],
# 
# ⁠["..Q.",  // 解法 2
# ⁠ "Q...",
# ⁠ "...Q",
# ⁠ ".Q.."]
# ]
# 解释: 4 皇后问题存在两个不同的解法。
# 
# 
# 
# 
# 提示：
# 
# 
# 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
# 
# 
#
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        queens = [-1] * n
        def canplace(row, col):
            for i in range(row):
                if (queens[i] == col):
                    return False
                if (row + col == i + queens[i] or row - col == i - queens[i]):
                    return False
            return True

        result = []
        def push():
            board = []
            for i in range(n):
                s = ['.'] * n
                s[queens[i]] = 'Q'
                board.append(''.join(s))
            result.append(board)

        def backtrack(start):
            nonlocal queens
            if (start == n):
                push()
                return
            for i in range(n):
                if (canplace(start, i)):
                    queens[start] = i
                    backtrack(start + 1)

        backtrack(0)
        return result
