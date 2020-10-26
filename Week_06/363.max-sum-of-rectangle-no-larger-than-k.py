#
# @lc app=leetcode.cn id=363 lang=python3
#
# [363] 矩形区域不超过 K 的最大数值和
#
# https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
#
# algorithms
# Hard (39.33%)
# Total Accepted:    5.8K
# Total Submissions: 14.5K
# Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
#
# 给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和。
# 
# 示例:
# 
# 输入: matrix = [[1,0,1],[0,-2,3]], k = 2
# 输出: 2 
# 解释: 矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
# 
# 
# 说明：
# 
# 
# 矩阵内的矩形区域面积必须大于 0。
# 如果行数远大于列数，你将如何解答呢？
# 
# 
#
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        if len(matrix) == 0:
            return 0
        height, width = len(matrix), len(matrix[0])
        result = float('-inf')
        for i in range(width):
            sums = [0] * height
            for j in range(i, width):
                for r in range(height):
                    sums[r] += matrix[r][j]
                accsums = [0]
                cum, max_sum = 0, float('-inf')
                for item in sums:
                    cum += item
                    pos = bisect.bisect_left(accsums, cum - k)
                    if pos < len(accsums):
                        max_sum = max(max_sum, cum - accsums[pos])
                    bisect.insort(accsums, cum)
                result = max(result, max_sum)
        return result
