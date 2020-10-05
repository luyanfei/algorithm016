/*
 * @lc app=leetcode.cn id=47 lang=golang
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (61.93%)
 * Total Accepted:    111.4K
 * Total Submissions: 179.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
func permuteUnique(nums []int) [][]int {
    sort.Ints(nums)
    result := [][]int{}
    visited := make([]int, len(nums), len(nums))
    item := []int{}
    var build func(first int)
    build = func(first int) {
        if first == len(nums) {
            result = append(result, append([]int{}, item...))
            return
        }
        for i := 0; i < len(nums); i++ {
            if visited[i] == 1 || (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == 1) {
                continue
            }
            item = append(item, nums[i])
            visited[i] = 1
            build(first + 1)
            visited[i] = 0
            item = item[:len(item) - 1]
        }
    }
    build(0)
    return result
}
