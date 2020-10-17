#
# @lc app=leetcode.cn id=64 lang=python3
#
# [64] Minimum Path Sum
#
# https://leetcode-cn.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (67.51%)
# Total Accepted:    141.8K
# Total Submissions: 210K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
# 
# 说明：每次只能向下或者向右移动一步。
# 
# 示例:
# 
# 输入:
# [
# [1,3,1],
# ⁠ [1,5,1],
# ⁠ [4,2,1]
# ]
# 输出: 7
# 解释: 因为路径 1→3→1→1→1 的总和最小。
# 
# 
#
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [x for x in grid[0]]
        for i in range(1, len(grid[0])):
            dp[i] += dp[i - 1]
        for i in range(1, len(grid)):
            for j in range(len(grid[0])):
                if j == 0:
                    dp[j] += grid[i][j]
                else:
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j]
        return dp[len(grid[0]) - 1]

