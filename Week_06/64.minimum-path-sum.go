/*
 * @lc app=leetcode.cn id=64 lang=golang
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (67.51%)
 * Total Accepted:    141.8K
 * Total Submissions: 210K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func minPathSum(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    height, width := len(grid), len(grid[0])
    for i := 0; i < height; i++ {
        for j := 0; j < width; j++ {
            if j > 0 && i == 0 {
                grid[i][j] += grid[i][j - 1]
            }
            if i > 0 && j == 0 {
                grid[i][j] += grid[i - 1][j]
            }
            if i > 0 && j > 0 {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
            }
        }
    }
    return grid[height - 1][width - 1]
}
