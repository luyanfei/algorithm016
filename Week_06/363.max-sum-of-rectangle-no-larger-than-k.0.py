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
        m, n = len(matrix), len(matrix[0])
        result = float('-inf')
        for i in range(n):
            subs = [0] * m
            for j in range(i, n):
                for t in range(m):
                    subs[t] += matrix[t][j]
                subsum, accs = 0, [0]
                for t in range(m):
                    subsum += subs[t]
                    pos = bisect.bisect_left(accs, subsum - k)
                    if pos < len(accs):
                        result = max(result, subsum - accs[pos])
                    bisect.insort(accs, subsum)
        return result
