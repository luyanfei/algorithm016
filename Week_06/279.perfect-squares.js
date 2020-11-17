/*
 * @lc app=leetcode.cn id=279 lang=javascript
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
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    let dp = new Array(n + 1)
    dp.fill(n + 1)
    dp[0] = 0
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= Math.sqrt(i); j++) {
            if (i - j * j >= 0) {
                dp[i] = Math.min(dp[i], dp[i - j * j] + 1)
            }
        }
    }
    return dp[n]
};
