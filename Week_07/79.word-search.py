#
# @lc app=leetcode.cn id=79 lang=python3
#
# [79] 单词搜索
#
# https://leetcode-cn.com/problems/word-search/description/
#
# algorithms
# Medium (43.63%)
# Total Accepted:    116.5K
# Total Submissions: 266.8K
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
# 
# 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
# 
# 
# 
# 示例:
# 
# board =
# [
# ⁠ ['A','B','C','E'],
# ⁠ ['S','F','C','S'],
# ⁠ ['A','D','E','E']
# ]
# 
# 给定 word = "ABCCED", 返回 true
# 给定 word = "SEE", 返回 true
# 给定 word = "ABCB", 返回 false
# 
# 
# 
# 提示：
# 
# 
# board 和 word 中只包含大写和小写英文字母。
# 1 <= board.length <= 200
# 1 <= board[i].length <= 200
# 1 <= word.length <= 10^3
# 
# 
#
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        height, width = len(board), len(board[0])
        def dfs(row, col, start):
            if row < 0 or row >= height or col < 0 or col >= width or board[row][col] == '.' or (start < len(word) and word[start] != board[row][col]):
                return False
            if start == len(word) - 1 and word[start] == board[row][col]:
                return True
            tmp = board[row][col]
            board[row][col] = '.'
            for i, j in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                if dfs(row + i, col + j, start + 1):
                    return True
            board[row][col] = tmp
            return False

        for i in range(height):
            for j in range(width):
                if dfs(i, j, 0):
                    return True
        return False
