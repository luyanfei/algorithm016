#
# @lc app=leetcode.cn id=647 lang=python3
#
# [647] 回文子串
#
# https://leetcode-cn.com/problems/palindromic-substrings/description/
#
# algorithms
# Medium (64.52%)
# Total Accepted:    67.7K
# Total Submissions: 105K
# Testcase Example:  '"abc"'
#
# 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
# 
# 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
# 
# 
# 
# 示例 1：
# 
# 输入："abc"
# 输出：3
# 解释：三个回文子串: "a", "b", "c"
# 
# 
# 示例 2：
# 
# 输入："aaa"
# 输出：6
# 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
# 
# 
# 
# 提示：
# 
# 
# 输入的字符串长度不会超过 1000 。
# 
# 
#
class Solution:
    def countSubstrings(self, s: str) -> int:
        t = '$#'
        for i in range(len(s)):
            t += s[i] + '#'
        t += '!'
        dp = [0] * len(t)
        imax, rmax, result = 0, 0, 0
        for i in range(1, len(t) - 1):
            if i > rmax:
                dp[i] = 1
            else:
                j = 2 * imax - i
                dp[i] = min(dp[j], rmax - i + 1)
            while t[i - dp[i]] == t[i + dp[i]]:
                dp[i] = dp[i] + 1
            if i + dp[i] - 1 > rmax:
                rmax = i + dp[i] - 1
                imax = i
            result += dp[i] // 2
        return result

#s = Solution()
#s.countSubstrings('abcd')
