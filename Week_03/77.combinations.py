#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#
# https://leetcode-cn.com/problems/combinations/description/
#
# algorithms
# Medium (75.72%)
# Total Accepted:    105.9K
# Total Submissions: 139.8K
# Testcase Example:  '4\n2'
#
# 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
# 
# 示例:
# 
# 输入: n = 4, k = 2
# 输出:
# [
# ⁠ [2,4],
# ⁠ [3,4],
# ⁠ [2,3],
# ⁠ [1,2],
# ⁠ [1,3],
# ⁠ [1,4],
# ]
# 
#
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        def build(start, preitem):
            item = list(preitem)
            if (len(item) == k):
                result.append(item)
                return
            if (start == n + 1 or n - start + 1 < k - len(item)):
                return
            build(start + 1, item)
            item.append(start)
            build(start + 1, item)
        build(1, [])
        return result
