#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#
# https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
#
# algorithms
# Medium (55.50%)
# Total Accepted:    180.1K
# Total Submissions: 324.5K
# Testcase Example:  '"23"'
#
# 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
# 
# 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
# 
# 
# 
# 示例:
# 
# 输入："23"
# 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
# 
# 
# 说明:
# 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
# 
#
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        keymaps = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        result = []
        if (len(digits) == 0):
            return result
        item = []
        def backtrack(start):
            nonlocal item
            if (start == len(digits)):
                result.append(''.join(item))
                return
            s = keymaps[digits[start]]
            for c in s:
                item.append(c)
                backtrack(start + 1)
                item = item[:-1]

        backtrack(0)
        return result
            
