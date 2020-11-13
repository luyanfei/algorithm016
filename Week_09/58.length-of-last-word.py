#
# @lc app=leetcode.cn id=58 lang=python3
#
# [58] 最后一个单词的长度
#
# https://leetcode-cn.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (33.75%)
# Total Accepted:    138.1K
# Total Submissions: 408.4K
# Testcase Example:  '"Hello World"'
#
# 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
# 
# 如果不存在最后一个单词，请返回 0 。
# 
# 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
# 
# 
# 
# 示例:
# 
# 输入: "Hello World"
# 输出: 5
# 
# 
#
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if len(s) == 0:
            return 0
        result, count = 0, 0
        for i in range(len(s)):
            if s[i] == ' ':
                result = count if count > 0 else result
                count = 0
            else:
                count += 1
                result = count
        return result
