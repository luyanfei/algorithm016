#
# @lc app=leetcode.cn id=212 lang=python3
#
# [212] 单词搜索 II
#
# https://leetcode-cn.com/problems/word-search-ii/description/
#
# algorithms
# Hard (42.89%)
# Total Accepted:    23.4K
# Total Submissions: 54K
# Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +  '["oath","pea","eat","rain"]'
#
# 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
# 
# 
# 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
# 
# 示例:
# 
# 输入: 
# words = ["oath","pea","eat","rain"] and board =
# [
# ⁠ ['o','a','a','n'],
# ⁠ ['e','t','a','e'],
# ⁠ ['i','h','k','r'],
# ⁠ ['i','f','l','v']
# ]
# 
# 输出: ["eat","oath"]
# 
# 说明:
# 你可以假设所有输入都由小写字母 a-z 组成。
# 
# 提示:
# 
# 
# 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
# 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
# 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
# 
# 
#
class Solution:
    def __init__(self):
        self.root = {}
        self.endchar = '#'

    def insert(self, word):
        node = self.root
        for w in word:
            node = node.setdefault(w, {})
        node[self.endchar] = self.endchar

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        for word in words:
            self.insert(word)
        result, item = set(), []
        height, width = len(board), len(board[0])
        def dfs(row, col, node):
            nonlocal item
            if row < 0 or row >= height or col < 0 or col >= width or board[row][col] == '.' or board[row][col] not in node:
                return
            node = node[board[row][col]]
            item.append(board[row][col])
            if self.endchar in node:
                result.add(''.join(item))
            tmp, board[row][col] = board[row][col], '.'
            for i, j in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                dfs(row + i, col + j, node)
            board[row][col] = tmp
            item = item[:-1]

        for i in range(height):
            for j in range(width):
                dfs(i, j, self.root)
        return [x for x in result]
