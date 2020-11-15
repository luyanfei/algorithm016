/*
 * @lc app=leetcode.cn id=152 lang=java
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
class Solution {
    public int maxProduct(int[] nums) {
        int smax = nums[0], smin = nums[0], result = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int tmax = Math.max(smax * nums[i], Math.max(nums[i], smin * nums[i]));
            int tmin = Math.min(smin * nums[i], Math.min(nums[i], smax * nums[i]));
            result = Math.max(result, tmax);
            smax = tmax;
            smin = tmin;
        }
        return result;
    }
}
