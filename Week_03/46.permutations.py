#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#
# https://leetcode-cn.com/problems/permutations/description/
#
# algorithms
# Medium (76.95%)
# Total Accepted:    198.8K
# Total Submissions: 258.4K
# Testcase Example:  '[1,2,3]'
#
# 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
# 
# 示例:
# 
# 输入: [1,2,3]
# 输出:
# [
# ⁠ [1,2,3],
# ⁠ [1,3,2],
# ⁠ [2,1,3],
# ⁠ [2,3,1],
# ⁠ [3,1,2],
# ⁠ [3,2,1]
# ]
# 
#
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        def build(start):
            if (start == n):
                result.append(list(nums))
                return
            for i in range(start, n):
                nums[start], nums[i] = nums[i], nums[start]
                build(start + 1)
                nums[start], nums[i] = nums[i], nums[start]
        build(0)
        return result

