#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 3Sum Closest
#
# https://leetcode-cn.com/problems/3sum-closest/description/
#
# algorithms
# Medium (45.83%)
# Total Accepted:    152.3K
# Total Submissions: 332.4K
# Testcase Example:  '[-1,2,1,-4]\n1'
#
# 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
# 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
# 
# 
# 
# 示例：
# 
# 输入：nums = [-1,2,1,-4], target = 1
# 输出：2
# 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
# 
# 
# 
# 
# 提示：
# 
# 
# 3 <= nums.length <= 10^3
# -10^3 <= nums[i] <= 10^3
# -10^4 <= target <= 10^4
# 
# 
#
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        mindis = 10 ** 5
        minsum = 0
        nums.sort()
        for i in range(len(nums) - 2):
            left, right = i + 1, len(nums) - 1
            t = target - nums[i]
            while left < right:
                sum3 = nums[left] + nums[right] + nums[i]
                dis = abs(sum3 - target)
                if (dis < mindis):
                    minsum = sum3
                    mindis = dis
                if (nums[left] + nums[right] < t):
                    left += 1
                else:
                    right -= 1
        return minsum
