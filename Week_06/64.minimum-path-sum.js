/*
 * @lc app=leetcode.cn id=64 lang=javascript
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
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    if (grid.length === 0) return 0
    let m = grid.length, n = grid[0].length
    for (let i = 1; i < n; i++) {
        grid[0][i] += grid[0][i - 1]
    }
    for (let i = 1; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (j === 0) {
                grid[i][j] += grid[i - 1][j]
            } else {
                grid[i][j] += Math.min(grid[i][j - 1], grid[i - 1][j])
            }
        }
    }
    return grid[m - 1][n - 1]
};
