/*
 * @lc app=leetcode.cn id=46 lang=golang
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.95%)
 * Total Accepted:    198.8K
 * Total Submissions: 258.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
func permute(nums []int) [][]int {
    result := [][]int{}
    var tranverse func(first int)
    tranverse = func(first int) {
        if first == len(nums) {
            result = append(result, append([]int{}, nums...))
            return
        }
        for i := first; i < len(nums); i++ {
            nums[i], nums[first] = nums[first], nums[i]
            tranverse(first + 1)
            nums[i], nums[first] = nums[first], nums[i]
        }
    }
    tranverse(0)
    return result
}
