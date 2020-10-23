/*
 * @lc app=leetcode.cn id=152 lang=javascript
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (40.34%)
 * Total Accepted:    97K
 * Total Submissions: 240.2K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    if (nums.length === 0) return 0
    let dpmin = nums[0], dpmax = nums[0], result = nums[0]
    for (let i = 1; i < nums.length; i++) {
        let t = Math.min(dpmin * nums[i], Math.min(dpmax * nums[i], nums[i]))
        dpmax = Math.max(dpmax * nums[i], Math.max(dpmin * nums[i], nums[i]))
        dpmin = t
        result = Math.max(result, dpmax)
    }
    return result
};
