/*
 * @lc app=leetcode.cn id=46 lang=javascript
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
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let result = [], item = [], n = nums.length
    let swap = function(i, j) {
        let t = nums[j]
        nums[j] = nums[i]
        nums[i] = t
    }
    let build = function(first) {
        if (first == n) {
            result.push([...item])
            return
        }
        for (let i = first; i < n; i++) {
            swap(first, i)
            item.push(nums[first])
            build(first + 1)
            item.pop()
            swap(first, i)
        }
    }
    build(0)
    return result
};
