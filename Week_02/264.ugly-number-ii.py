#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#
# https://leetcode-cn.com/problems/ugly-number-ii/description/
#
# algorithms
# Medium (53.97%)
# Total Accepted:    35.2K
# Total Submissions: 65.2K
# Testcase Example:  '10'
#
# 编写一个程序，找出第 n 个丑数。
# 
# 丑数就是质因数只包含 2, 3, 5 的正整数。
# 
# 示例:
# 
# 输入: n = 10
# 输出: 12
# 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
# 
# 说明:  
# 
# 
# 1 是丑数。
# n 不超过1690。
# 
# 
#
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        s = {1}
        heap = [1]
        while (n > 1):
            top = heapq.heappop(heap)
            for x in [2, 3, 5]:
                num = top * x
                if not num in s:
                    s.add(num)
                    heapq.heappush(heap, num)
            n -= 1
        return heap[0]
