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
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        flags = [False] * len(nums)
        item, result = [], []
        def permute(start):
            nonlocal item
            if start == len(nums):
                result.append(list(item))
                return
            for i in range(len(nums)):
                if flags[i] or (i > 0 and nums[i] == nums[i - 1] and flags[i - 1]):
                    continue
                flags[i] = True
                item.append(nums[i])
                permute(start + 1)
                item = item[:len(item) - 1]
                flags[i] = False
        permute(0)
        return result
