#
# @lc app=leetcode.cn id=621 lang=python3
#
# [621] 任务调度器
#
# https://leetcode-cn.com/problems/task-scheduler/description/
#
# algorithms
# Medium (51.14%)
# Total Accepted:    33.7K
# Total Submissions: 65.8K
# Testcase Example:  '["A","A","A","B","B","B"]\n2'
#
# 给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26
# 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
# 
# 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
# 
# 你需要计算完成所有任务所需要的最短时间。
# 
# 
# 
# 示例 ：
# 
# 输入：tasks = ["A","A","A","B","B","B"], n = 2
# 输出：8
# 解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
# ⁠    在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。 
# 
# 
# 
# 提示：
# 
# 
# 任务的总个数为 [1, 10000]。
# n 的取值范围为 [0, 100]。
# 
# 
#
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        table = [0] * 26
        for i in range(len(tasks)):
            table[ord(tasks[i]) - ord('A')] += 1
        table.sort(reverse = True)
        count, k = 0, table[0]
        while count < len(table) and table[count] == k:
            count += 1
        return max(len(tasks), (k - 1) * (n + 1) + count)
