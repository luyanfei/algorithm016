/*
 * @lc app=leetcode.cn id=78 lang=golang
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.03%)
 * Total Accepted:    156K
 * Total Submissions: 197.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
func subsets(nums []int) [][]int {
    result := [][]int{[]int{}}
    for i := 0; i < len(nums); i++ {
        newitems := [][]int{}
        for j := 0; j < len(result); j++ {
            newitem := append([]int{}, result[j]...)
            newitems = append(newitems, append(newitem, nums[i]))
        }
        result = append(result, newitems...)
    }
    return result
}
