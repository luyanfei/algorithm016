#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#
# https://leetcode-cn.com/problems/longest-valid-parentheses/description/
#
# algorithms
# Hard (33.94%)
# Total Accepted:    107.6K
# Total Submissions: 316.9K
# Testcase Example:  '"(()"'
#
# 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
# 
# 示例 1:
# 
# 输入: "(()"
# 输出: 2
# 解释: 最长有效括号子串为 "()"
# 
# 
# 示例 2:
# 
# 输入: ")()())"
# 输出: 4
# 解释: 最长有效括号子串为 "()()"
# 
# 
#
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        if n < 2:
            return 0
        dp = [0] * n
        dp[1] = 2 if s[:2] == '()' else 0
        for i in range(2, n):
            if s[i - 1 : i + 1] == '()':
                dp[i] = dp[i - 2] + 2
            if s[i - 1 : i + 1] == '))' and i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(':
                if i - dp[i - 1] - 2 >= 0:
                    dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2
                else:
                    dp[i] = dp[i - 1] + 2
        return max(dp)
