/*
 * @lc app=leetcode.cn id=47 lang=javascript
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
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums.sort((a, b) => a - b)
    let result = []
    let visited = new Array(nums.length)
    visited.fill(0)
    let item = []
    function build(first) {
        if (first == nums.length) {
            result.push([...item])
            return
        }
        for (let i = 0; i < nums.length; i++) {
            if (visited[i] == 1 || (i > 0 && visited[i - 1] == 1 && nums[i - 1] == nums[i])) {
                continue
            }
            item.push(nums[i])
            visited[i] = 1
            build(first + 1)
            visited[i] = 0
            item.pop()
        }
    }
    build(0)
    return result
};
