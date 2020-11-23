/*
 * @lc app=leetcode.cn id=221 lang=javascript
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (42.95%)
 * Total Accepted:    76K
 * Total Submissions: 176.8K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    if (matrix.length === 0) return 0
    let m = matrix.length, n = matrix[0].length
    let dp = new Array(m)
    for (let i = 0; i < m; i++) {
        dp[i] = new Array(n)
    }
    let maxwidth = 0
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            dp[i][j] = matrix[i][j] === '1' ? 1 : 0
            if (i > 0 && j > 0 && matrix[i][j] === '1') {
                dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1
            }
            maxwidth = Math.max(maxwidth, dp[i][j])
        }
    }
    return maxwidth * maxwidth
};
