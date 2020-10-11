/*
 * @lc app=leetcode.cn id=15 lang=javascript
 *
 * [15] 3Sum
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.35%)
 * Total Accepted:    319.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a, b) => a - b)
    let result = []
    for (let i = 0; i < nums.length; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue
        }
        for (let j = i + 1, k = nums.length - 1; j < k;) {
            if (j > i + 1 && nums[j] === nums[j - 1]) {
                j++
                continue
            }
            let sum2 = nums[j] + nums[k]
            if (sum2 === -nums[i]) {
                result.push([nums[i], nums[j], nums[k]])
                j++
                k--
            } else if (sum2 < -nums[i]) {
                j++
            } else {
                k--
            }
        }
    }
    return result
};

