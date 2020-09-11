#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 3Sum
#
# https://leetcode-cn.com/problems/3sum/description/
#
# algorithms
# Medium (29.35%)
# Total Accepted:    319.7K
# Total Submissions: 1.1M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
# ？请你找出所有满足条件且不重复的三元组。
# 
# 注意：答案中不可以包含重复的三元组。
# 
# 
# 
# 示例：
# 
# 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
# 
# 满足要求的三元组集合为：
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
# 
# 
#
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        for i in range(len(nums)):
            if i != 0 and nums[i-1] == nums[i]:
                continue
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if nums[left] + nums[right] == -nums[i]:
                    result.append([nums[i], nums[left], nums[right]])
                    left = left + 1
                    while nums[left - 1] == nums[left] and left < right:
                        left = left + 1
                    right = right - 1
                    while nums[right  + 1] == nums[right] and left < right:
                        right = right - 1
                elif nums[left] + nums[right] < -nums[i]:
                    left = left + 1
                else:
                    right = right - 1
        return result
