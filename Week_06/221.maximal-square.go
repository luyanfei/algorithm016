/*
 * @lc app=leetcode.cn id=221 lang=golang
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
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func maximalSquare(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }
    height, width := len(matrix), len(matrix[0])
    dp := make([][]int, height)
    maxlen := 0
    for i := 0; i < height; i++ {
        dp[i] = make([]int, width)
    }

    for i := 0; i < width; i++ {
        dp[0][i] = int(matrix[0][i] - '0')
        maxlen = max(maxlen, dp[0][i])
    }
    for i := 1; i < height; i++ {
        for j := 0; j < width; j++ {
            if j == 0 {
                dp[i][j] = int(matrix[i][j] - '0')
            } else if matrix[i][j] == '0' {
                dp[i][j] = 0
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1
            }
            maxlen = max(maxlen, dp[i][j])
        }
    }
    return maxlen * maxlen
}
