/*
 * @lc app=leetcode.cn id=77 lang=golang
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (75.72%)
 * Total Accepted:    105.9K
 * Total Submissions: 139.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
func combine(n int, k int) [][]int {
    result := [][]int{}
    item := []int{}
    var build func(first int)
    build = func(first int) {
        if len(item) == k {
            result = append(result, append([]int{}, item...))
            return
        }
        if first > n {
            return
        }
        build(first + 1)
        item = append(item, first)
        build(first + 1)
        item = item[:len(item) - 1]
    }
    build(1)
    return result
}
