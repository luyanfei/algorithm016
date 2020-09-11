#
# @lc app=leetcode.cn id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
#
# https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
#
# algorithms
# Hard (41.65%)
# Total Accepted:    86.8K
# Total Submissions: 208.4K
# Testcase Example:  '[2,1,5,6,2,3]'
#
# 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
# 
# 求在该柱状图中，能够勾勒出来的矩形的最大面积。
# 
# 
# 
# 
# 
# 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
# 
# 
# 
# 
# 
# 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
# 
# 
# 
# 示例:
# 
# 输入: [2,1,5,6,2,3]
# 输出: 10
# 
#
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        n = len(heights)
        left = [0] * n
        right = [n] * n
        for i in range(n):
            while len(stack) != 0 and heights[stack[-1]] > heights[i]:
                right[stack[-1]] = i
                stack.pop()
            left[i] = stack[-1] if len(stack) != 0 else -1
            stack.append(i)
        area = 0
        for i in range(n):
            area = max(area, heights[i] * (right[i] - left[i] - 1))
        return area
