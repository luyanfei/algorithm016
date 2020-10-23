/*
 * @lc app=leetcode.cn id=279 lang=golang
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (58.03%)
 * Total Accepted:    90.9K
 * Total Submissions: 156.6K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func numSquares(n int) int {
    dp := make([]int, n + 1)
    for i := 0; i < n + 1; i++ {
        dp[i] = n + 1
    }
    dp[0] = 0
    for i := 1; i < n + 1; i++ {
        for k := 1; k * k <= i; k++ {
            dp[i] = min(dp[i], dp[i - k * k] + 1)
        }
    }
    return dp[n]
}
