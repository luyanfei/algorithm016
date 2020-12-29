#
# @lc app=leetcode.cn id=316 lang=python3
#
# [316] 去除重复字母
#
# https://leetcode-cn.com/problems/remove-duplicate-letters/description/
#
# algorithms
# Medium (42.69%)
# Total Accepted:    40.2K
# Total Submissions: 86.2K
# Testcase Example:  '"bcabc"'
#
# 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
# 
# 注意：该题与 1081
# https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
# 相同
# 
# 
# 
# 示例 1：
# 
# 
# 输入：s = "bcabc"
# 输出："abc"
# 
# 
# 示例 2：
# 
# 
# 输入：s = "cbacdcbc"
# 输出："acdb"
# 
# 
# 
# 提示：
# 
# 
# 1 
# s 由小写英文字母组成
# 
# 
#
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter = collections.Counter(s)
        used = set()
        item = []
        for c in s:
            if c in used:
                counter[c] -= 1
                continue
            while len(item) > 0 and ord(item[len(item) - 1]) > ord(c) and counter[item[len(item) - 1]] > 0:
                used.remove(item[len(item) - 1])
                item = item[:-1]
            cunter[c] -= 1
            used.add(c)
            item += [c]
        return ''.join(item)
