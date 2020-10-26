#
# @lc app=leetcode.cn id=410 lang=python3
#
# [410] 分割数组的最大值
#
# https://leetcode-cn.com/problems/split-array-largest-sum/description/
#
# algorithms
# Hard (53.00%)
# Total Accepted:    25.2K
# Total Submissions: 47.4K
# Testcase Example:  '[7,2,5,10,8]\n2'
#
# 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
# 
# 注意:
# 数组长度 n 满足以下条件:
# 
# 
# 1 ≤ n ≤ 1000
# 1 ≤ m ≤ min(50, n)
# 
# 
# 示例: 
# 
# 
# 输入:
# nums = [7,2,5,10,8]
# m = 2
# 
# 输出:
# 18
# 
# 解释:
# 一共有四种方法将nums分割为2个子数组。
# 其中最好的方式是将其分为[7,2,5] 和 [10,8]，
# 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
# 
# 
#
class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        if len(nums) == 0:
            return 0
        dp = [[math.inf] * (m + 1) for _ in range(len(nums) + 1)]
        dp[0][0] = 0
        subs = [0] * (len(nums) + 1)
        for i in range(len(subs) - 1):
            subs[i + 1] = subs[i] + nums[i]
        for i in range(1, len(nums) + 1):
            for j in range(1, m + 1):
                for k in range(i):
                    dp[i][j] = min(max(dp[k][j - 1], subs[i] - subs[k]), dp[i][j])
        return dp[len(nums)][m]
