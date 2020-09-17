#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] Group Anagrams
#
# https://leetcode-cn.com/problems/group-anagrams/description/
#
# algorithms
# Medium (63.37%)
# Total Accepted:    105.5K
# Total Submissions: 166.2K
# Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
#
# 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
# 
# 示例:
# 
# 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
# 输出:
# [
# ⁠ ["ate","eat","tea"],
# ⁠ ["nat","tan"],
# ⁠ ["bat"]
# ]
# 
# 说明：
# 
# 
# 所有输入均为小写字母。
# 不考虑答案输出的顺序。
# 
# 
#
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        table = {}
        for s in strs:
            chars = [0] * 26
            for c in s:
                chars[ord(c) - ord('a')] += 1
            //如果将其转换成字符串作为key，则可能出现不同单词有相同key的情形
            //如：[["bbbbbbbbbbc"],["bdddddddddd"]]
            //key=010100000000000000000000000
            //key=010100000000000000000000000
            key = tuple(chars)
            table.setdefault(key, []).append(s)
        return list(table.values())
