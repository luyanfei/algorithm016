#
# @lc app=leetcode.cn id=47 lang=python3
#
# [47] 全排列 II
#
# https://leetcode-cn.com/problems/permutations-ii/description/
#
# algorithms
# Medium (61.93%)
# Total Accepted:    111.4K
# Total Submissions: 179.8K
# Testcase Example:  '[1,1,2]'
#
# 给定一个可包含重复数字的序列，返回所有不重复的全排列。
# 
# 示例:
# 
# 输入: [1,1,2]
# 输出:
# [
# ⁠ [1,1,2],
# ⁠ [1,2,1],
# ⁠ [2,1,1]
# ]
# 
#
#from typing import List
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        used = [False] * n
        item = []
        result = []
        def tranverse(first):
            nonlocal used, item
            if (first == n):
                result.append(list(item))
                return
            for idx, val in enumerate(nums):
                if (used[idx] or (idx > 0 and nums[idx - 1] == nums[idx] and not used[idx - 1])):
                    continue
                item.append(val)
                used[idx] = True
                tranverse(first + 1)
                used[idx] = False
                item = item[:-1]
        tranverse(0)
        return result

#sol = Solution()
#nums = [1, 1, 2]
#r = sol.permuteUnique(nums)
#print(r)
