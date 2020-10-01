/*
 * @lc app=leetcode.cn id=16 lang=javascript
 *
 * [16] 3Sum Closest
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.83%)
 * Total Accepted:    152.3K
 * Total Submissions: 332.4K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    let result
    let mindis = 10 ** 5
    nums.sort((a, b) => a - b)
    //for (let i = 0; i < nums.length; i++) {
        //console.log(nums[i])
    //}
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1, k = nums.length - 1; j < k;) {
            let sum = nums[i] + nums[j] + nums[k]
            if (Math.abs(sum - target) < mindis) {
                result = sum
                mindis = Math.abs(sum - target)
            }
            //console.log("i=" + i + ",j=" + j + ",k=" + k +",sum=" + sum)
            if (nums[j] + nums[k] < target - nums[i]) {
                j++
            } else {
                k--
            }
        }
    }
    return result
};

//var arr = [1,2,4,8,16,32,64,128]
//threeSumClosest(arr, 82)
