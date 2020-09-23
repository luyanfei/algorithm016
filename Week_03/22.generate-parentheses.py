#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#
# https://leetcode-cn.com/problems/generate-parentheses/description/
#
# algorithms
# Medium (76.23%)
# Total Accepted:    180.8K
# Total Submissions: 237.1K
# Testcase Example:  '3'
#
# 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
# 
# 
# 
# 示例：
# 
# 输入：n = 3
# 输出：[
# ⁠      "((()))",
# ⁠      "(()())",
# ⁠      "(())()",
# ⁠      "()(())",
# ⁠      "()()()"
# ⁠    ]
# 
# 
#
class Solution:
    def generate(self, n, s, left, right, result):
        if (left == n and right == n):
            result.append(s)
            return
        if (left < n):
            s1 = s + '('
            self.generate(n, s1, left + 1, right, result)
        if (right < left):
            s2 = s + ')'
            self.generate(n, s2, left, right + 1, result)

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        self.generate(n, "", 0, 0, result)
        return result
